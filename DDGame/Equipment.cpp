#include "stdafx.h"
#include "Equipment.h"


Equipment::Equipment(){
}
Equipment::~Equipment(){
}

bool Equipment::compare(Item* item1, Item* item2) {
	return (item1->getName() == item2->getName());
}
bool Equipment::isOverweight(float weight, float capacity){
	return weight>float(capacity);
}

bool Equipment::hasItem(Item * theItem){
	for (int i = 0; i < (int)(equipment.size()); i++) {
		if (compare(theItem, equipment.at(i))) return true;
	}
	return false;
}


void Equipment::addItem(Item* theitem, string name, AbilityScores theScores, ArmorClass AC, Speed& spd) {
	int response;
	string responseYN;
	cout << "How many " << theitem->getName() << "s did you want to include? ";
	cin >> response;
	Util.checkNumericUserInput(response,1);
	theitem->raiseAMT(response);
	if (equipment.empty()) { 
		equipment.push_back(theitem);
		promptEquip(0,theScores.getAMod(1),theScores.getAMod(0), responseYN,AC);
	}
	else {
		int i = 0;
		for (; i < (int)(equipment.size()); i++) {
			if (compare(theitem, equipment.at(i))) {
				(equipment.at(i))->raiseAMT((theitem)->getAMT());
				break;
			}
			else if (i = equipment.size()) {
				equipment.push_back(theitem);
				promptEquip(0, theScores.getAMod(1), theScores.getAMod(0), responseYN, AC);
			}
			
		}
		
	}
	updateTotalWeight(name, theScores, spd);
}
void Equipment::removeItem(string name, AbilityScores theScores, Speed& Spd, bool isReq){
	int response;
	auto iter = equipment.begin();
	int amt;
	cout << "\n" << name << "'s Equipment:";
	while (isReq) {
		for (int i = 0; i < int(equipment.size()); i++) {
			cout << "\n    " << i + 1 << ") " << equipment.at(i)->getName() << " x" << equipment.at(i)->getAMT();
			if (equipment.at(i)->isEquippable()) {
			}
		}
		cout << "\nWhich item do you want to remove? ";
		cin >> response;
		Util.checkNumericUserInput(response, 1, equipment.size());
		cout << "How many " << equipment.at(response-1)->getName() << "s do you want to remove? ";
		cin >> amt;
		Util.checkNumericUserInput(amt, 0, equipment.at(response-1)->getAMT());
		if(amt==equipment.at(response-1)->getAMT()) equipment.erase(iter + response-1);
		else equipment.at(response-1)->raiseAMT(-amt);
		updateTotalWeight(name, theScores, Spd);
		if (getTotalWeight() < theScores.getCarryCapacity()) {
			isReq = false;
		}
	}
	
}

void Equipment::setEquipment(string name, AbilityScores theScores, ArmorClass AC, Speed& Spd){
	bool isDone=false;
	int value;
	vector<int> input;
	while (!isDone) {
		cout << "\nWhat kind of equipment do you want to add to " << name << "'s inventory?"
			 << "\n    0) Finished Adding Equipment"
			 << "\n    1) Armor"
			 << "\n    2) Weapons"
			 << "\nEquipment Type: ";
		cin >> value;
		Util.checkNumericUserInput(value, 0, 2);
		input.push_back(value);
		if (input.at(0) == 0) isDone = true;
		while (input.at(0) == 1) {
			cout << "\nWhat kind of armor do you want to add to " << name << "'s inventory?"
				 << "\n    0) Finished adding Armor"
				 << "\n    1) Light Armor"
				 << "\n    2) Medium Armor"
				 << "\n    3) Heavy Armor"
				 << "\n    4) Shield"
				 << "\nArmor Type: ";
			cin >> value;
			Util.checkNumericUserInput(value, 0, 4);
			if (value == 4) addItem(new Armor("Shield", "A shield is made from wood or metal and is carried in one hand. Wielding a shield increases your Armor Class by 2. You can benefit from only one shield at a time.", 6, 10, 2, 3, 0, true, true), name, theScores,AC, Spd);
			else if (value > 0) {
				input.push_back(value);
				while (input.at(1) == 1) {
					cout << "\nWhat kind of Light Armor do you want to add to " << name << "'s inventory?"
						 << "\n    0) Finished adding Light Armor"
						 << "\n    1) Padded"
						 << "\n    2) Leather"
						 << "\n    3) Studded Leather"
						 << "\nLight Armor Type: ";
					cin >> value;
					Util.checkNumericUserInput(value, 0, 3);
					if (value == 0) input.at(1) = 4;
					else if (value == 1) addItem(new Armor("Padded Armor", "Padded armor consists of quilted layers of cloth and batting", 8.0f, 5, 11, 0, 0, false), name, theScores, AC, Spd);
					else if (value == 2) addItem(new Armor("Leather Armor", "The Breastplate and shoulder protectors of this armor are made of leather that has been stiffened by being boiled in oil. The rest of the armor is made of softer and more flexible materials.", 10.0f, 10, 11, 0, 0, true), name, theScores, AC, Spd);
					else addItem(new Armor("Studded Leather Armor", "Made from tough but flexible leather, studded leather is reinforced with close-set rivets or spikes.", 13.0f, 45, 12, 0, 0, true), name, theScores, AC, Spd);
				}
				while (input.at(1) == 2) {
					cout << "\nWhat kind of Medium Armor do you want to add to " << name << "'s inventory? "
						 << "\n    0) Finished adding Medium Armor"
						 << "\n    1) Hide Armor"
						 << "\n    2) Chain Shirt"
						 << "\n    3) Scale Mail"
						 << "\n    4) Breastplate"
						 << "\n    5) Half Plate"
						 << "\nMedium Armor Type: ";
					cin >> value;
					Util.checkNumericUserInput(value, 0, 5);
					if (value == 0) input.at(1) = 4;
					else if (value == 1) addItem(new Armor("Hide Armor", "This crude armor consists of thick furs and pelts. It is commonly worn by Barbarian tribes, evil humanoids, and other folk who lack access to the tools and materials needed to create better armor.", 12.0f, 10, 12, 1, 0, true), name, theScores, AC, Spd);
					else if (value == 2) addItem(new Armor("Chain Shirt", "Made of interlocking metal rings, a chain shirt is worn between layers of clothing or leather. This armor offers modest protection to the wearer's upper body and allows the sound of the rings rubbing against one another to be muffled by outer layers.", 20.0f, 50, 13, 1, 0, true), name, theScores, AC, Spd);
					else if (value == 3) addItem(new Armor("Scale Mail", "This armor consists of a coat and leggings (and perhaps a separate skirt) of leather covered with overlapping pieces of metal, much like the scales of a fish. The suit includes gauntlets.", 45.0f, 50, 14, 1, 0, false), name, theScores, AC, Spd);
					else if (value == 4) addItem(new Armor("Breastplate", "This armor consists of a fitted metal chest piece worn with supple leather. Although it leaves the legs and arms relatively unprotected, this armor provides good protection for the wearer's vital organs while leaving the wearer relatively unencumbered.", 20.0f, 400, 14, 1, 0, true), name, theScores, AC, Spd);
					else addItem(new Armor("Half Plate", "Half plate consists of shaped metal plates that cover most of the wearer's body. It does not include leg protection beyond simple greaves that are attached with leather straps.", 40.0f, 750, 15, 1, 0, false), name, theScores, AC, Spd);
				}
				while (input.at(1) == 3) {
					cout << "\nWhat kind of Heavy Armor do you want to add to " << name << "'s inventory?"
						 << "\n    0) Finished adding Heavy Armor"
						 << "\n    1) Ring Mail"
						 << "\n    2) Chain Mail"
						 << "\n    3) Splint Armor"
						 << "\n    4) Plate Armor"
						 << "\nHeavy Armor Type: ";
					cin >> value;
					Util.checkNumericUserInput(value, 0, 4);
					if (value == 0) input.at(1) = 4;
					else if (value == 1) addItem(new Armor("Ring Mail", "This armor is Leather Armor with heavy rings sewn into it. The rings help reinforce the armor against blows from swords and axes. Ring mail is inferior to Chain Mail, and it's usually worn only by those who can't afford better armor.", 40.0f, 30, 14, 2, 0, false), name, theScores, AC, Spd);
					else if (value == 2) addItem(new Armor("Chain Mail", "Made of interlocking metal rings, chain mail includes a layer of quilted fabric worn underneath the mail to prevent chafing and to cushion the impact of blows. The suit includes gauntlets.", 55.0f, 75, 16, 2, 13, false), name, theScores, AC, Spd);
					else if (value == 3) addItem(new Armor("Splint Armor", "This armor is made of narrow vertical strips of metal riveted to a backing of leather that is worn over cloth padding. Flexible Chain Mail protects the joints.", 60.0f, 200, 17, 2, 15, false), name, theScores, AC, Spd);
					else addItem(new Armor("Plate Armor", "Plate consists of shaped, interlocking metal plates to cover the entire body. A suit of plate includes gauntlets, heavy leather boots, a visored helmet, and thick layers of padding underneath the armor. Buckles and straps distribute the weight over the body.", 65.0f, 1500, 18, 2, 15, false), name, theScores, AC, Spd);
				}
				input.pop_back();
			}
			else input.at(0) = 3;
		}
		while (input.at(0) == 2) {
			cout << "\nWhat kind of Weapon do you want to add to " << name << "'s inventory?"
				 << "\n    0) Finished Adding Weapons"
				 << "\n    1) Simple Weapons"
				 << "\n    2) Martial Weapons"
				 << "\nWeapon Type: ";
			cin >> value;
			Util.checkNumericUserInput(value, 0, 2);
			if (value > 0) {
				input.push_back(value);
				while (input.at(1) == 1) {
					cout << "\nWhat kind of Simple Weapon do you want to add to " << name << "'s inventory?"
						<< "\n    0) Finished adding Simple Weapons"
						<< "\n    1) Simple Melee Weapons"
						<< "\n    2) Simple Ranged Weapons"
						<< "\nSimple Weapon Type: ";
					cin >> value;
					Util.checkNumericUserInput(value, 0, 2);
					if (value > 0) {
						input.push_back(value);
						bool Prop[14];
						while (input.at(2) == 1) {
							for (int i = 0; i < 14; i++) Prop[i] = false;
							cout << "\nWhat kind of Simple Melee Weapon do you want to add to " << name << "'s inventory?"
								 << "\n    0) Finished adding Simple Melee Weapons"           
								 << "\n    1) Club ( 1d4 B, Light )"
								 << "\n    2) Dagger ( 1d4 P, Finesse, Light, Thrown(20/60) )"
								 << "\n    3) Greatclub ( 1d8 B, Two-Handed )"
								 << "\n    4) Handaxe ( 1d6 S, Light, Thrown(20/60) )"
								 << "\n    5) Javelin ( 1d6 P, Thrown(30/120) )"
								 << "\n    6) Light Hammer ( 1d4 B, Light, Thrown(20/60) )"
								 << "\n    7) Mace ( 1d6 B )"
								 << "\n    8) Quarterstaff ( 1d6 B, Versatile(1d8) )"
								 << "\n    9) Sickle ( 1d4 S, Light )"
								 << "\n    10) Spear ( 1d6 P, Thrown(20/60), Versatile(1d8) )"
								 << "\nSimple Melee Weapon Type: ";
							cin >> value;
							Util.checkNumericUserInput(value, 0, 10);
							switch (value) {
								case 0:
									input.at(2) = 3;
								case 1:
									Prop[3] = true;
									addItem(new Weapon("Club", "A beating stick...or maybe a nunchuck. Your choice.", 2.0f, .1f, 1, 4, 1, 5, Prop), name, theScores, AC, Spd);
									break;
								case 2:
									Prop[1] = true; Prop[3] = true; Prop[6] = true;
									addItem(new Weapon("Dagger", "Favorite weapon of criminals everywhere, light, easily concealed, and very pointy.", 1.0f, 2.0f, 1, 4, 2, 60, Prop), name, theScores, AC, Spd);
									break;
								case 3:
									Prop[6] = true;
									addItem(new Weapon("Greatclub", "A beating stick; a really big beating stick.", 10.0f, .2f, 1, 8, 1, 5, Prop), name, theScores, AC, Spd);
									break;
								case 4:
									Prop[3] = true; Prop[5] = true;
									addItem(new Weapon("Handaxe", "Think a tomahawk, except with less (or maybe more) scalping", 2.0f, 5.0f, 1, 6, 3, 60, Prop), name, theScores, AC, Spd);
									break;
								case 5:
									Prop[5] = true;
									addItem(new Weapon("Javelin", "It's a spear, only...better for throwing", 2.0f, .5f, 1, 6, 2, 120, Prop), name, theScores, AC, Spd);
									break;
								case 6:
									Prop[3] = true; Prop[5] = true;
									addItem(new Weapon("Light Hammer", "A hammer...That is thrown. No this doesn't make you Thor.", 2.0f, 2.0f, 1, 4, 1, 60, Prop), name, theScores, AC, Spd);
									break;
								case 7:
									addItem(new Weapon("Mace", "A club. With a very heavy piece of metal on it. But still basically a club.", 4.0f, 5.0f, 1, 6, 1, 5, Prop), name, theScores, AC, Spd);
									break;
								case 8:
									Prop[7] = true;
									addItem(new Weapon("Quarterstaff", "A beating stick. A really long one.", 4.0f, .2f, 1, 6, 1, 5, Prop), name, theScores, AC, Spd);
									break;
								case 9:
									Prop[3] = true;;
									addItem(new Weapon("Sickle", "This bladed stick is sick-le...Puns.", 2.0f, 1.0f, 1, 4, 3, 5, Prop), name, theScores, AC, Spd);
									break;
								default:
									Prop[5] = true; Prop[7] = true;
									addItem(new Weapon("Spear", "A long stick with a pointy end. <Insert dirty joke here>",3.0f,1.0f,1,6,2,60,Prop), name, theScores, AC, Spd);
							}
						}
						while (input.at(2) == 2) {
							cout << "\nWhat kind of Simple Ranged Weapon do you want to add to " << name << "'s inventory?"
								 << "\n    0) Finished Adding Simple Ranged Weapons"
								 << "\n    1) Light Crossbow ( 1d8 P, Ammunition(80/320), Loading, Two-Handed )"
								 << "\n    2) Dart ( 1d4 P, Finesse, Thrown(20/60) )"
								 << "\n    3) Shortbow ( 1d6 P, Ammunition (80/320), Two-Handed )"
								 << "\n    4) Sling    ( 1d4 B, Ammunition (30/120) )"
								 << "\nSimple Ranged Weapon Type: ";
							cin >> value;
							Util.checkNumericUserInput(value, 0, 4);
							switch (value) {
								case 0:
									input.at(2) = 3;
									break;
								case 1:
									Prop[0] = true;
									addItem(new Weapon("Light Crossbow", "The overly complicated version of a shortbow; Hits slightly harder, fires much slower. ", 5.0f, 25.0f, 1, 8, 2, 320, Prop), name, theScores, AC, Spd);
									break;
								case 2:
									Prop[1] = true; Prop[5] = true;
									addItem(new Weapon("Dart", "A really long needle. But please, everyone thinks of it as a shuriken", .25f, .05f, 1, 4, 2, 60, Prop), name, theScores, AC, Spd);
									break;
								case 3:
									Prop[0] = true; Prop[6] = true;
									addItem(new Weapon("Shortbow", "A short bow. For the small creatures, or the Plebs who can't use longbows", 2.0f, 25.0f, 1, 6, 2, 320, Prop), name, theScores, AC, Spd);
									break;
								default:
									Prop[0] = true;
									addItem(new Weapon("Sling", "If you are using this rock slingshot, either you are doing something wrong, or something very right", 0.0f, .1f, 1, 4, 1, 120, Prop), name, theScores, AC, Spd);
									break;
							}
						}
						input.pop_back();
					}
					else input.at(1) = 3;
				}
				while (input.at(1) == 2) {
					cout << "\nWhat kind of Martial Weapon do you want to add to " << name << "'s inventory?"
						 << "\n    0) Finished Adding Martial Weapons"
						 << "\n    1) Martial Melee Weapons"
						 << "\n    2) Martial Ranged Weapons"
						 << "\nMartial Weapon Type: ";
					cin >> value;
					Util.checkNumericUserInput(value, 0, 2);
					if (value == 0) input.at(1) = 3;
					else {
						input.push_back(value);
						bool Prop[14];
						while (input.at(2) == 1) {
							for (int i = 0; i < 14; i++) Prop[i] = false;
							cout << "\n What kind of Martial Melee Weapon do you want to add to " << name << "'s inventory?"
								 << "\n    0) Finished Adding Martial Melee Weapons"
								 << "\n    1) Battleaxe ( 1d8 S, Versatile(1d10 S) )"
								 << "\n    2) Flail ( 1d8 B )"
								 << "\n    3) Glaive ( 1d10 S, Heavy, Reach, Two-Handed )"
								 << "\n    4) Greataxe ( 1d12 S, Heavy, Two-Handed )"
								 << "\n    5) Greatsword ( 2d6 S, Heavy Two-Handed )"
								 << "\n    6) Halberd ( 1d10 S, Heavy, Reach, Two-Handed )"
								 << "\n    7) Lance ( 1d12 P, Reach, Special )"
								 << "\n    8) Longsword ( 1d8 S, Versatile(1d10) )"
								 << "\n    9) Maul ( 2d6 B, Heavy, Two-Handed )"
								 << "\n   10) Morningstar ( 1d8 P )"
								 << "\n   11) Pike ( 1d10 P, Heavy, Reach, Two-Handed )"
								 << "\n   12) Rapier ( 1d8 P, Finesse )"
								 << "\n   13) Scimitar ( 1d6 S, Finesse, Light )"
								 << "\n   14) Shortsword ( 1d6 P, Finesse Light )"
								 << "\n   15) Trident ( 1d6 P, Thrown(20/60), Versatile(1d8) )"
								 << "\n   16) War Pick ( 1d8 P )"
								 << "\n   17) Warhammer (1d8 B, Versatile(1d10) )"
								 << "\n   18) Whip (1d4 S, Finesse, Reach )"
								 << "\nMartial Melee Weapon Type: ";
							cin >> value;
							Util.checkNumericUserInput(value, 0, 17);
							switch (value) {
								case 0:
									input.at(2) = 3;
									break;
								case 1:
									Prop[7] = true;
									addItem(new Weapon("Battleaxe", "", 4.0f, 10.0f, 1, 8, 3, 5, Prop), name, theScores, AC, Spd);
									break;
								case 2:
									addItem(new Weapon("Flail", "", 2.0f, 10.0f, 1, 8, 1, 5, Prop), name, theScores, AC, Spd);
									break;
								case 3:
									Prop[2] = Prop[6] = true;
									addItem(new Weapon("Glaive", "", 6.0f, 20.0f, 1, 10, 3, 10, Prop), name, theScores, AC, Spd);
									break;
								case 4:
									Prop[2] = Prop[6] = true;
									addItem(new Weapon("Greataxe", "", 7.0f, 30.0f, 1, 12, 3, 5, Prop), name, theScores, AC, Spd);
									break;
								case 5:
									Prop[2] = Prop[6] = true;
									addItem(new Weapon("Greatsword", "", 6.0f, 50.0f, 2, 6, 3, 5, Prop), name, theScores, AC, Spd);
									break;
								case 6:
									Prop[2] = Prop[6] = true;
									addItem(new Weapon("Halberd", "", 6.0f, 20.0f, 1, 10, 3, 10, Prop), name, theScores, AC, Spd);
									break;
								case 7:
									Prop[10] = true;
									addItem(new Weapon("Lance", "", 6.0f, 10.0f, 1, 12, 2, 10, Prop), name, theScores, AC, Spd);
									break;
								case 8:
									Prop[7] = true;
									addItem(new Weapon("Longsword", "", 3.0f, 15.0f, 1, 8, 3, 5, Prop), name, theScores, AC, Spd);
									break;
								case 9:
									Prop[2] = Prop[6] = true;
									addItem(new Weapon("Maul", "", 10.0f, 10.0f, 2, 6, 1, 5, Prop), name, theScores, AC, Spd);
									break;
								case 10:
									addItem(new Weapon("Morningstar", "", 4.0f, 15.0f, 1, 8, 2, 5, Prop), name, theScores, AC, Spd);
									break;
								case 11:
									Prop[2] = Prop[6] = true;
									addItem(new Weapon("Pike", "", 18.0f, 5.0f, 1, 10, 2, 10, Prop), name, theScores, AC, Spd);
									break;
								case 12:
									Prop[1] = true;
									addItem(new Weapon("Rapier", "", 2.0f, 25.0f, 1, 25, 2, 5, Prop), name, theScores, AC, Spd);
									break;
								case 13:
									Prop[1] = Prop[3] = true;
									addItem(new Weapon("Scimitar", "", 3.0f, 25.0f, 1, 6, 3, 5, Prop), name, theScores, AC, Spd);
									break;
								case 14:
									Prop[1] = Prop[3] = true;
									addItem(new Weapon("Shortsword", "", 2.0f, 10.0f, 1, 6, 2, 5, Prop), name, theScores, AC, Spd);
									break;
								case 15:
									Prop[5] = Prop[7] = true;
									addItem(new Weapon("Trident", "", 4.0f, 5.0f, 1, 6, 2, 60, Prop), name, theScores, AC, Spd);
									break; 
								case 16:
									addItem(new Weapon("War Pick", "", 2.0f, 5.0f, 1, 8, 2, 5, Prop), name, theScores, AC, Spd);
									break;
								case 17:
									Prop[7] = true;
									addItem(new Weapon("Warhammer", "", 2.0f, 15.0f, 1, 8, 1, 5, Prop), name, theScores, AC, Spd);
									break;
								case 18:
									Prop[1] = true;
									addItem(new Weapon("Whip", "", 3.0f, 2.0f, 1, 4, 3, 10, Prop), name, theScores, AC, Spd);
							}
						} 
						while (input.at(2) == 2) {
							for (int i = 0; i < 14; i++) Prop[i] = false;
							cout << "\nWhat kind of Martial Ranged Weapon do you want to add to " << name << "'s inventory?"
								 << "\n    0) Finished Adding Martial Ranged Weapons"
								 << "\n    1) Blowgun ( 1 P, Ammunition(25/100), Loading )"
								 << "\n    2) Hand Crossbow ( 1d6 P, Ammunition(30/120), Light, Loading )"
								 << "\n    3) Heavy Crossbow (1d10 P, Ammunition(100/400), Heavy, Loading, Two-Handed )"
								 << "\n    4) Longbow (1d8 P, Ammunition(150/600), Heavy, Two-Handed )"
								 << "\n    5) Net (Special, Thrown(5/15) )"
								 << "\nMartial Ranged Weapon Type: ";
							cin >> value;
							Util.checkNumericUserInput(value, 0, 5);
							switch (value) {
								case 0:
									input.at(2) = 3;
									break;
								case 1:
									Prop[0] = true; Prop[4] = true;
									addItem(new Weapon("Blowgun", "Does little to no damage and requires reloading. Just great. But you can poison the darts", 1.0f, 10.0f, 1, 1, 2, 100, Prop), name, theScores, AC, Spd);
									break;
								case 2:
									Prop[0] = true; Prop[3] = true; Prop[4] = true;
									addItem(new Weapon("Hand Crossbow", "Slow your roll Demon Hunter! One handed crossbow which does only as much as a shortbow, and shoots slowly.", 3.0f, 75.0f, 1, 6, 2, 120, Prop), name, theScores, AC, Spd);
									break;
								case 3:
									Prop[0] = true; Prop[2] = true; Prop[4] = true;
									addItem(new Weapon("Heavy Crossbow", "They say bigger is better. And this is a heavy hitting--but still slow--crossbow", 18.0f, 50.0f, 1, 10, 2, 400, Prop), name, theScores, AC, Spd);
									break;
								case 4:
									Prop[0] = true; Prop[2] = true; Prop[6] = true;
									addItem(new Weapon("Longbow", "King over all the Pleb ranged weapons, hits slightly weaker than the heavy crossbow without sacrificing speed, and from very far away", 2.0f, 50.0f, 1, 8, 2, 600, Prop), name, theScores, AC, Spd);
									break;
								case 5:
									Prop[5] = true; Prop[12] = true;
									addItem(new Weapon("Net", "Wait. This is a Weapon?! Well, it entangles caught enemies.", 3.0f, 1.0f, 1, 0, 0, 15, Prop), name, theScores, AC, Spd);
							}
						}
						input.pop_back();
					}
				}
				input.pop_back();
			}
			else input.at(0) = 3;
		}
		input.pop_back();
	}
}

float Equipment::getTotalWeight(){
	return TotalWeight;
}
void Equipment::updateTotalWeight(string name, AbilityScores theScores, Speed& Spd) {
	TotalWeight = 0;
	for (int i = 0; i < int(equipment.size()); i++) TotalWeight += ((equipment.at(i))->getAMT()*(equipment.at(i))->getWeight()); //this can be better
	if (isOverweight(getTotalWeight(), theScores.getCarryCapacity())) {
		cout << "\n" << name << "'s Weight: " << getTotalWeight() << " lbs exceeds " << name << "'s Carrying Capacity: " << theScores.getCarryCapacity() << " lbs. An item must be removed.";
		removeItem(name, theScores, Spd, true);
	}
	else if (isOverweight(getTotalWeight(),theScores.getEncumberance()[1])) {
		string response;
		while (response == "Y") {
			cout << "\n" << name << " is heavily encumbered (Weight: " << getTotalWeight() << " lbs > Threshold: " << theScores.getEncumberance()[1] << " lbs). Speed drops by 20 feet and " << name << " has disadvantage on all ability checks, attack rolls, and saving throws that use STR DEX or CON. It is strongly reccomended this condition be removed by lowering weight."
				 << "\nWould you like to remove some equipment (Y: Yes N: No)? ";
			cin >> response;
			Util.checkYNUserInput(response);
			if (response == "Y") removeItem(name, theScores, Spd, true);
		}
		if (theScores.getEncumberance()[1] <= getTotalWeight()) Spd.updateSpeed(theScores.getEncumberance(), getTotalWeight());
	}
	else if (isOverweight(getTotalWeight(), theScores.getEncumberance()[0])) {
		string response="Y";
		while(response == "Y") {
			cout << "\nCaution: " << name << " is encumbered (Weight: "<<getTotalWeight()<<" lbs > Threshold: "<< theScores.getEncumberance()[0] <<" lbs). Speed drops by 10 feet."
				 << "\nWould you like to remove some equipment (Y: Yes N: No)? ";
			cin >> response;
			Util.checkYNUserInput(response);
			if (response == "Y") removeItem(name, theScores, Spd, true);
		}
		if (theScores.getEncumberance()[0] <= getTotalWeight()) Spd.updateSpeed(theScores.getEncumberance(), getTotalWeight());
	} 
	else cout << "Current Weight: " << getTotalWeight();
}

void Equipment::promptEquip(int index, int dexScore, int strScore, string YN, ArmorClass AC){
	if (equipment.at(index)->isEquippable()) {
		cout << "\nWould you like to equip " << equipment.at(index)->getName() << " (Y: Yes N: No)? ";
		cin >> YN;
		Util.checkYNUserInput(YN);
		if (YN == "Y") {
			equipment.at(index)->Equip(AC, dexScore, strScore);
		}
	}
}

