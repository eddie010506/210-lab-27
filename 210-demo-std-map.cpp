#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
#include <limits>
using namespace std;
// new code to print after each operation
void printAllVillagers(const map<string, tuple<int, string, string>>& villager) {
    cout << "\nVillager details:" << endl;
    for (auto const& pair : villager) {
        cout << pair.first << " [" << get<0>(pair.second)
             << ", " << get<1>(pair.second)
             << ", " << get<2>(pair.second)
             << "]" << endl;
    }
    cout << endl;
}
int main() {
    // declarations
    map<string, tuple<int, string, string>> villager;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villager["Audie"] = make_tuple(5,"Human","Hello ");
    villager["Raymond"] = make_tuple(8,"Dog","Wolf-Wolf ");
    villager.insert({"Marshal", make_tuple(8,"CAt","Meow ")});

     


    int choice = 0;// making menu
    while (choice != 4) {
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        string name;
        map<string, tuple<int, string, string>>::iterator it;
        switch (choice) {
            case 1: {// adding villager
                string species, catchphrase;
                int level;

                cout << "Villager name: ";
                cin >> name;
                cout << "Friendship level: ";
                cin >> level;
                cout << "Species: ";
                cin >> species;
                cout << "Catchphrase: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');// to take away the leftover line
                getline(cin, catchphrase);

                villager[name] = make_tuple(level, species, catchphrase);
                cout << name << " added." << endl;
                
                printAllVillagers(villager);
                break;
            }

            case 2: {//delete villager
                cout << "Enter villager name to delete: ";
                cin >> name;

                if (villager.erase(name) == 1) { 
                    cout << name << " deleted." << endl;
                } else {
                    cout << "Error: " << name << " not found." << endl;
                }
                printAllVillagers(villager);
                break;
            }
            case 3: {
                cout << "Enter villager name: ";
                cin >> name;
                it = villager.find(name);
                if (it == villager.end()) {
                    cout << "Error: " << name << " not found." << endl;
                } 
                else if (choice == 1) { //increasing
                    get<0>(it->second)++; 
                }
            }
            printAllVillagers(villager); 
            break;
                


            

            case 4: { //same code but check if friend ship bigger than 0
                cout << "Enter villager name: ";
                cin >> name;
                it = villager.find(name);
                if (it == villager.end()) {
                    cout << "Error: " << name << " not found." << endl;
                } 
                else if (choice == 2) { //decreasing
                    if (get<0>(it->second) > 0) { 
                            get<0>(it->second)--; 
                            cout << name << "'s friendship decreased." << endl;
                    } 
                    else {
                        cout << name << "'s friendship is already 0." << endl;
                    }
                }
            }
            printAllVillagers(villager); 
            break;

            case 5: {
                cout << "Enter villager name: ";
                cin >> name;
                it = villager.find(name);

                if (it == villager.end()) {
                    cout << "Error: " << name << " not found." << endl;
                } else {
                    // print the found villager's details
                    cout << "Found " << it->first  << get<0>(it->second)<< ", " << get<1>(it->second)<< ", " << get<2>(it->second)<< endl;
                }
                printAllVillagers(villager); 
                break;
            } 

            case 6: // exit
            {
                cout << "Exiting." << endl;
                break;
            } 

            default: // invalid Input
            {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
                


    }
    return 0;
}
