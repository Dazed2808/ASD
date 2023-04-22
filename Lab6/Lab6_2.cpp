/*#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

// Structure to store car rental information
struct CarRentalInfo {
    string numberPlate;
    string carMake;
    int year;
    string driverSurname;
    time_t rentalTime;
    int rentalDuration;
    double rentalPrice;
};

// Structure for linked list node
struct Node {
    CarRentalInfo info;
    Node* next;
};

// Linked list class
class CarRentalList {
public:
    CarRentalList() {
        head = nullptr;
    }
    void addToEnd(CarRentalInfo carRentalInfo) {
        Node* newNode = new Node;
        newNode->info = carRentalInfo;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    void addToStart(CarRentalInfo carRentalInfo) {
        Node* newNode = new Node;
        newNode->info = carRentalInfo;
        newNode->next = head;
        head = newNode;
    }
    void addToMiddle(CarRentalInfo carRentalInfo, int index) {
        if (index < 0) {
            return;
        }
        if (index == 0) {
            addToStart(carRentalInfo);
        }
        else {
            Node* newNode = new Node;
            newNode->info = carRentalInfo;
            int i = 0;
            Node* curr = head;
            Node* prev = nullptr;
            while (curr != nullptr && i < index) {
                prev = curr;
                curr = curr->next;
                i++;
            }
            if (i == index) {
                prev->next = newNode;
                newNode->next = curr;
            }
            else {
                delete newNode;
            }
        }
    }
    void removeFromStart() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void removeFromMiddle(int index) {
        if (index < 0) {
            return;
        }
        if (index == 0) {
            removeFromStart();
        }
        else {
            int i = 0;
            Node* curr = head;
            Node* prev = nullptr;
            while (curr != nullptr && i < index) {
                prev = curr;
                curr = curr->next;
                i++;
            }
            if (i == index) {
                prev->next = curr->next;
                delete curr;
            }
        }
    }
    void removeFromEnd() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            Node* curr = head;
            Node* prev = nullptr;
            while (curr->next != nullptr) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            delete curr;
        }
    }
    void printList() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        }
        else {
            Node* curr = head;
            while (curr != nullptr) {
                printCarRentalInfo(curr->info);
                curr = curr->next;
            }
        }
    }
    void searchByNumberPlate(string numberPlate) {
        Node* curr = head;
        int index = 0;
        while (curr != nullptr) {
            if (curr->info.numberPlate == numberPlate) {
                cout << "Car rental information at index " << index << ": " << endl;
                printCarRentalInfo(curr->info);
            }
            curr = curr->next;
            index++;
        }
    }
    void searchByCarMake(string carMake) {
        Node* curr = head;
        int index = 0;
        while (curr != nullptr) {
            if (curr->info.carMake == carMake) {
                cout << "Car rental information at index " << index << ": " << endl;
                printCarRentalInfo(curr->info);
            }
            curr = curr->next;
            index++;
        }
    }
    void searchByRentalDate(time_t rentalDate) {
        Node* curr = head;
        int index = 0;
        while (curr != nullptr) {
            if (curr->info.rentalTime <= rentalDate && curr->info.rentalTime + curr->info.rentalDuration >= rentalDate) {
                cout << "Car rental information at index " << index << ": " << endl;
                printCarRentalInfo(curr->info);
            }
            curr = curr->next;
            index++;
        }
    }
    void sortByNumberPlate() {
        bool swapped = true;
        while (swapped) {
            swapped = false;
            Node* curr = head;
            Node* prev = nullptr;
            while (curr != nullptr && curr->next != nullptr) {
                if (curr->info.numberPlate > curr->next->info.numberPlate) {
                    swapNodeData(curr, curr->next);
                    swapped = true;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }
    void sortByCarMake() {
        bool swapped = true;
        while (swapped) {
            swapped = false;
            Node* curr = head;
            Node* prev = nullptr;
            while (curr != nullptr && curr->next != nullptr) {
                if (curr->info.carMake > curr->next->info.carMake) {
                    swapNodeData(curr, curr->next);
                    swapped = true;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }
private:
    void printCarRentalInfo(CarRentalInfo carRentalInfo) {
        cout << "Number plate: " << carRentalInfo.numberPlate << endl;
        cout << "Car make: " << carRentalInfo.carMake << endl;
        cout << "Year of manufacture: " << carRentalInfo.year << endl;
        cout << "Driver's surname: " << carRentalInfo.driverSurname << endl;
        cout << "Rental date and time: " << ctime(&carRentalInfo.rentalTime);
        cout << "Rental duration: " << carRentalInfo.rentalDuration << " hours/days" << endl;
        cout << "Rental price: " << carRentalInfo.rentalPrice << " per hour/day" << endl;
        cout << endl;
    }
    void swapNodeData(Node* node1, Node* node2) {
        CarRentalInfo temp = node1->info;
        node1->info = node2->info;
        node2->info = temp;
    }
    Node* head;
};

// Function to parse a line of text and return a car rental info object
CarRentalInfo parseCarRentalInfo(string line) {
    CarRentalInfo carRentalInfo;
    string token;
    int i = 0;
    size_t pos = 0;
    while ((pos = line.find(",")) != string::npos) {
        token = line.substr(0, pos);
        switch (i) {
        case 0:
            carRentalInfo.numberPlate = token;
            break;
        case 1:
            carRentalInfo.carMake = token;
            break;
        case 2:
            carRentalInfo.year = stoi(token);
            break;
        case 3:
            carRentalInfo.driverSurname = token;
            break;
        case 4:
            carRentalInfo.rentalTime = stoi(token);
            break;
        case 5:
            carRentalInfo.rentalDuration = stoi(token);
            break;
        case 6:
            carRentalInfo.rentalPrice = stod(token);
            break;
        }
        line.erase(0, pos + 1);
        i++;
    }
    return carRentalInfo;
}

// Function to get the current system time
time_t getCurrentTime() {
    time_t now = time(0);
    return now;
}

int main() {
    CarRentalList carRentalList;
    ifstream file("Test.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            CarRentalInfo carRentalInfo = parseCarRentalInfo(line);
            carRentalList.addToEnd(carRentalInfo);
        }
        file.close();
    }
    else {
        cout << "Unable to open file" << endl;
        return 0;
    }
    int choice;
    do {
        cout << "Select an option: " << endl;
        cout << "1. Add a car rental information to the end of the list" << endl;
        cout << "2. Add a car rental information to the start of the list" << endl;
        cout << "3. Add a car rental information to the middle of the list" << endl;
        cout << "4. Remove a car rental information from the start of the list" << endl;
        cout << "5. Remove a car rental information from the middle of the list" << endl;
        cout << "6. Remove a car rental information from the end of the list" << endl;
        cout << "7. Print the list" << endl;
        cout << "8. Search for a car rental by number plate" << endl;
        cout << "9. Search for a car rental by car make" << endl;
        cout << "10. Search for a car rental by rental date and time" << endl;
        cout << "11. Sort the list by number plate" << endl;
        cout << "12. Sort the list by car make" << endl;
        cout << "13. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            CarRentalInfo newRentalInfo;
            cout << "Enter the car rental information: " << endl;
            cout << "Number plate: ";
            cin >> newRentalInfo.numberPlate;
            cout << "Car make: ";
            cin >> newRentalInfo.carMake;
            cout << "Year of manufacture: ";
            cin >> newRentalInfo.year;
            cout << "Driver's surname: ";
            cin >> newRentalInfo.driverSurname;
            cout << "Rental duration (in hours / days): ";
            cin >> newRentalInfo.rentalDuration;
            cout << "Rental price (per hour / day): ";
            cin >> newRentalInfo.rentalPrice;
            newRentalInfo.rentalTime = getCurrentTime();
            carRentalList.addToEnd(newRentalInfo);
            break;
        case 2:
            CarRentalInfo newStartRentalInfo;
            cout << "Enter the car rental information: " << endl;
            cout << "Number plate: ";
            cin >> newStartRentalInfo.numberPlate;
            cout << "Car make: ";
            cin >> newStartRentalInfo.carMake;
            cout << "Year of manufacture: ";
            cin >> newStartRentalInfo.year;
            cout << "Driver's surname: ";
            cin >> newStartRentalInfo.driverSurname;
            cout << "Rental duration (in hours / days): ";
            cin >> newStartRentalInfo.rentalDuration;
            cout << "Rental price (per hour / day): ";
            cin >> newStartRentalInfo.rentalPrice;
            newStartRentalInfo.rentalTime = getCurrentTime();
            carRentalList.addToStart(newStartRentalInfo);
            break;
        case 3:
            CarRentalInfo newMiddleRentalInfo;
            int index;
            cout << "Enter the car rental information: " << endl;
            cout << "Number plate: ";
            cin >> newMiddleRentalInfo.numberPlate;
            cout << "Car make: ";
            cin >> newMiddleRentalInfo.carMake;
            cout << "Year of manufacture: ";
            cin >> newMiddleRentalInfo.year;
            cout << "Driver's surname: ";
            cin >> newMiddleRentalInfo.driverSurname;
            cout << "Rental duration (in hours / days): ";
            cin >> newMiddleRentalInfo.rentalDuration;
            cout << "Rental price (per hour / day): ";
            cin >> newMiddleRentalInfo.rentalPrice;
            newMiddleRentalInfo.rentalTime = getCurrentundefined*/



#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Car {
    string plate;
    string brand;
    int year;
    string driver;
    string date;
    int hours;
    float price;
};

const int MAX_CARS = 100;
Car cars[MAX_CARS];
int num_cars = 0;

void load_data(string filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: could not open file " << filename << endl;
        return;
    }
    while (num_cars < MAX_CARS && file >> cars[num_cars].plate
            >> cars[num_cars].brand >> cars[num_cars].year
            >> cars[num_cars].driver >> cars[num_cars].date
            >> cars[num_cars].hours >> cars[num_cars].price) {
        num_cars++;
    }
    file.close();
}

void print_car(const Car& car) {
    cout << car.plate << "\t" << car.brand << "\t" << car.year
         << "\t" << car.driver << "\t" << car.date << "\t"
         << car.hours << "\t" << car.price << endl;
}

void print_all_cars() {
    for (int i = 0; i < num_cars; i++) {
        print_car(cars[i]);
    }
}

int find_car_by_plate(const string& plate) {
    for (int i = 0; i < num_cars; i++) {
        if (cars[i].plate == plate) {
            return i;
        }
    }
    return -1;
}

int find_car_by_brand(const string& brand) {
    for (int i = 0; i < num_cars; i++) {
        if (cars[i].brand == brand) {
            return i;
        }
    }
    return -1;
}

void add_car(const Car& car, int index) {
    if (num_cars >= MAX_CARS) {
        cout << "Error: maximum number of cars reached" << endl;
        return;
    }
    if (index < 0 || index > num_cars) {
        cout << "Error: invalid index" << endl;
        return;
    }
    for (int i = num_cars - 1; i >= index; i--) {
        cars[i + 1] = cars[i];
    }
    cars[index] = car;
    num_cars++;
}

void remove_car(int index) {
    if (index < 0 || index >= num_cars) {
        cout << "Error: invalid index" << endl;
        return;
    }
    for (int i = index; i < num_cars - 1; i++) {
        cars[i] = cars[i + 1];
    }
    num_cars--;
}

void return_car(const string& plate) {
    int index = find_car_by_plate(plate);
    if (index == -1) {
        cout << "Error: car not found" << endl;
        return;
    }
    cars[index].date = "";
    cars[index].hours = 0;
}

void sort_cars_by_plate() {
    int i, j, min_index;
    Car temp_car;
    for (i = 0; i < num_cars - 1; i++) {
        min_index = i;
        for (j = i + 1; j < num_cars; j++) {
            if (cars[j].plate < cars[min_index].plate) {
            min_index = j;
            }
        }
        if (min_index != i) {
            temp_car = cars[i];
            cars[i] = cars[min_index];
            cars[min_index] = temp_car;
        }
    }
}

void sort_cars_by_brand() {
    for (int i = 0; i < num_cars - 1; i++) {
        for (int j = i + 1; j < num_cars; j++) {
            if (cars[j].brand < cars[i].brand) {
            Car temp_car = cars[i];
            cars[i] = cars[j];
            cars[j] = temp_car;
            }
        }
    }
}

void search_available_cars(const string& date) {
    for (int i = 0; i < num_cars; i++) {
        if (cars[i].date != date) {
            continue;
        }
        cout << cars[i].plate << "\t" << cars[i].brand << endl;
    }
}

int main() {
    load_data("Test.txt");
    while (true) {
        cout << "MENU" << endl;
        cout << "1. Add car at beginning" << endl;
        cout << "2. Add car at end" << endl;
        cout << "3. Add car at index" << endl;
        cout << "4. Remove car from beginning" << endl;
        cout << "5. Remove car from end" << endl;
        cout << "6. Remove car from index" << endl;
        cout << "7. Print all cars" << endl;
        cout << "9. Return car" << endl;
        cout << "10. Sort cars by plate" << endl;
        cout << "11. Sort cars by brand" << endl;
        cout << "12. Search available cars" << endl;
        cout << "0. Exit" << endl;
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 0:
                return 0;
            case 1: {
                Car car;
                cout << "Enter car plate: ";
                cin >> car.plate;
                cout << "Enter car brand: ";
                cin >> car.brand;
                cout << "Enter car year: ";
                cin >> car.year;
                cout << "Enter driver name: ";
                cin >> car.driver;
                cout << "Enter date: ";
                cin >> car.date;
                cout << "Enter hours: ";
                cin >> car.hours;
                cout << "Enter price per hour: ";
                cin >> car.price;
                add_car(car, 0);
                break;
            }
            case 2: {
                Car car;
                cout << "Enter car plate: ";
                cin >> car.plate;
                cout << "Enter car brand: ";
                cin >> car.brand;
                cout << "Enter car year: ";
                cin >> car.year;
                cout << "Enter driver name: ";
                cin >> car.driver;
                cout << "Enter date: ";
                cin >> car.date;
                cout << "Enter hours: ";
                cin >> car.hours;
                cout << "Enter price per hour: ";
                cin >> car.price;
                add_car(car, num_cars);
                break;
            }
            case 3: {
                int index;
                cout << "Enter index: ";
                cin >> index;
                if (index < 0 || index > num_cars) {
                    cout << "Invalid index" << endl;
                    break;
                }
                Car car;
                cout << "Enter car plate: ";
                cin >> car.plate;
                cout << "Enter car brand: ";
                cin >> car.brand;
                cout << "Enter car year: ";
                cin >> car.year;
                cout << "Enter driver name: ";
                cin >> car.driver;
                cout << "Enter date: ";
                cin >> car.date;
                cout << "Enter hours: ";
                cin >> car.hours;
                cout << "Enter price per hour: ";
                cin >> car.price;
                add_car(car, index);
                break;
            }
            case 4:
                remove_car(0);
                break;
            case 5:
                remove_car(num_cars - 1);
                break;
            case 6: {
                int index;
                cout << "Enter index: ";
                cin >> index;
                if (index < 0 || index >= num_cars) {
                    cout << "Invalid index" << endl;
                    break;
                }
                remove_car(index);
                break;
            }
            case 7:
                print_all_cars();
                break;
            case 9: {
                string plate;
                cout << "Enter car plate: ";
                cin >> plate;
                return_car(plate);
                break;
            }
            case 10:
                sort_cars_by_plate();
                break;
            case 11:
                sort_cars_by_brand();
                break;
            case 12: {
                string date;
                cout << "Enter date: ";
                cin >> date;
                search_available_cars(date);
                break;
            }
            default:
                cout << "Invalid choice" << endl;
            }
    }
    return 0;
}
