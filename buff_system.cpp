#include <iostream>
#include <ctime>
#include <vector>

void RollBonuses(bool hasAvg, int B_Amount, int pBonuses_Size, std::vector<std::string>pBonuses, std::string UsedBonuses[], int SizeOfBonuses [], int AvgDmgValue, int SkillDmgValue, int B_Size);

int main() {
  int B_Amount;
  int B_AmountAvg;
  int B_Size;
  int B_Type;
  int pBonuses_Size;
  int SizeOfBonuses[6];
  int AvgDmgValue;
  int SkillDmgValue;
  bool hasAvg;
  char hasAvg_Response;
  char start_Response;
  char restart_Response;

  const std::string AvalableBonuses [17] = {"Strong Against Half Human", "Strong Against Mystic",
  "Strong Against Orcs", "Strong Against Devils", "Strong Against Animals", "Strong Against Undead", "Chance of Piercing Hit", "Chance of Critical Hit", "Poison Chance",     //BONUSES LISTS
  "Chance of Blackout", "Bleeding attack", "Slowing Chance", "Spell Speed", "Intelligence", "Strength", "Dexterity", "Vitality" };

  std::vector<std::string>pBonuses;

  std::cout << "------------ BONUSES SIMULATOR. ONLY WEAPON AVALABLE SO FAR ------------\n";
  std::cout << "Does it have Avg damage?(y/n): ";
  std::cin >> hasAvg_Response;
  if (hasAvg_Response != 'y' && hasAvg_Response != 'n') {
    do {
     std::cout << "Incorrect input, please write y or n: ";
     std::cin >> hasAvg_Response;
    } while (hasAvg_Response != 'y' && hasAvg_Response != 'n');
  }
  if (hasAvg_Response == 'y'){
    hasAvg = true;
  }
  else {
    hasAvg = false;
  }
  if (hasAvg == false) {
    std::cout << "Number of bonuses (1-6): ";     //Number of bonuses get declared
    std::cin >> B_Amount;
    while (B_Amount < 1 || B_Amount > 6) {
      std::cout << "Wrong number, introduce a number between 1 and 6: ";
      std::cin >> B_Amount;
    }
  }
  else {
    std::cout << "Number of bonuses (0-4): ";     //Number of bonuses get declared
    std::cin >> B_Amount;
    while (B_Amount < 0 || B_Amount > 4) {
      std::cout << "Wrong number, introduce a number between 0 and 4: ";
      std::cin >> B_Amount;
    }
  }
  std::string UsedBonuses [B_Amount] = {};
  srand(time(0));
  do {
    for (const std::string& word : AvalableBonuses) {
      pBonuses.push_back(word);
    }
    std::cout << "Start?(y/n): ";
    std::cin >> start_Response;
    if (start_Response == 'y' || start_Response == 'Y') {
      std::cout << "Your enchantments are: \n";
      RollBonuses(hasAvg, B_Amount, pBonuses_Size, pBonuses, UsedBonuses, SizeOfBonuses, AvgDmgValue, SkillDmgValue, B_Size);
    }
    else if(start_Response == 'n' || start_Response == 'N') {
      std::cout << "Exiting the program." << std::endl;
      break;
    }
    else {
      std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
    }
  } while (true);

  std::cin.ignore();
  std::cin.get();


}

void RollBonuses(bool hasAvg, int B_Amount, int pBonuses_Size, std::vector<std::string>pBonuses, std::string UsedBonuses[], int SizeOfBonuses [], int AvgDmgValue, int SkillDmgValue, int B_Size){
  if (hasAvg == false) {
    for (int i = 0; i < B_Amount; i++){                     //Randomizes The name of the Bonus from the list
      pBonuses_Size = pBonuses.size();
      int randNum = rand() % pBonuses_Size;
      UsedBonuses[i] = pBonuses[randNum];
      pBonuses.erase(pBonuses.begin() + randNum);
      SizeOfBonuses [i] = randNum;
    }
  }
  else {
    AvgDmgValue = rand() % 71 - 20;
    if (AvgDmgValue > 20) {
      SkillDmgValue = rand () % 41 - 30;
    }
    else {
      SkillDmgValue = rand() % 10 + 20;
    }
    std::cout << "Average Damage " << AvgDmgValue << "%\n" << "Skill Damage: " << SkillDmgValue << "%\n";
    for (int i = 0; i < B_Amount; i++){                    
      pBonuses_Size = pBonuses.size();
      int randNum = rand() % pBonuses_Size;
      UsedBonuses[i] = pBonuses[randNum];
      pBonuses.erase(pBonuses.begin() + randNum);
      SizeOfBonuses [i] = randNum;
    }
  }
  for (int i = 0; i < B_Amount; i++){         //Outputs Each bonus and its % 
    if (UsedBonuses [i] == "Strong Against Half Human" || UsedBonuses [i] == "Chance of Piercing Hit" || UsedBonuses [i] == "Chance of Critical Hit") {
      B_Size = (rand() % 6) + 5;
     }
      else if (UsedBonuses [i] == "Strong Against Mystic"|| UsedBonuses [i] ==  "Strong Against Orcs"|| UsedBonuses [i] ==  "Strong Against Devils"
        || UsedBonuses [i] ==   "Strong Against Animals"|| UsedBonuses [i] ==   "Strong Against Undead"|| UsedBonuses [i] == "Spell Speed") {
        B_Size = (rand() % 11) + 10;
      }
      else if (UsedBonuses [i] == "Poison Chance"|| UsedBonuses [i] == "Chance of Blackout"|| UsedBonuses [i] == "Bleeding attack"|| UsedBonuses [i] == "Slowing Chance") {
        B_Size = (rand() % 5) + 4;
      }
      else if (UsedBonuses [i] == "Intelligence"|| UsedBonuses [i] == "Strength"|| UsedBonuses [i] == "Dexterity"|| UsedBonuses [i] == "Vitality") {
       B_Size = (rand() % 7) + 6;
      }
      else {
        std::cout << "INVALID SIZE DETERMINATION CHECK";
      }
      if (UsedBonuses[i] == "Intelligence" || UsedBonuses[i] == "Strength" || UsedBonuses[i] == "Dexterity" || UsedBonuses[i] == "Vitality") {
        std::cout << UsedBonuses[i] << " + " << B_Size << '\n';
     }
      else {
        std::cout << UsedBonuses[i] << ' ' << B_Size << "%\n";
      }
 }
  pBonuses.clear();
 for (int i = 0; i < 17; i++){   //Resets the strings
    UsedBonuses [i] = "null";
    SizeOfBonuses[i] = 1;
  }
}
 



