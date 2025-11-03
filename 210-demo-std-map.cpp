#include <iostream>
#include <map>
#include <vector>
#include <tuple>
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

    // access the map using a range-based for loop
    cout << "Villagers and their info" << endl;
    for (auto const& pair : villager) {
        cout << pair.first << ": "<< get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villager.begin(); 
                                               it != villager.end(); ++it) {
        cout << it->first << get<0>(it->second)<< ", " << get<1>(it->second)<< ", " << get<2>(it->second)<< endl;
    }

    // delete an element
    villager.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villager.find(searchKey);
    if (it != villager.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        cout << "\nFound " << searchKey << "'s details: ";cout << get<0>(it->second)<< ", " << get<1>(it->second)<< ", " << get<2>(it->second) << endl;
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villager.size() << endl;
    villager.clear();
    cout << "Size after clear: " << villager.size() << endl;

    int choice = 0;// making menu
    while (choice != 4) {
        cout << "1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search for Villager" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        string name;
        auto it;
        switch (choice){
            case 1: {
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
                


            }

            case 2: { //same code but check if friend ship bigger than 0
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
                


        }
        
    }
    return 0;
}
