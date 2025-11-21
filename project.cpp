#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

class Contact {
    string name;
    string email;
    string phone;
public:
    Contact() {}
    Contact(string n, string p, string e) {
        name = n;
        email = e;
        phone = p;
    }
    friend class ContactManager;
    void display() {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "phone: " << phone << endl;
        cout << "________________________" << endl;
    }
};

class ContactManager{
    vector<Contact> contacts;
public:
    friend class Contact;
    void addContact() {
        Contact c;
        cout << "Please add contact information:" << endl;
        cout << "Name: ";
        cin >> c.name;
        cout << "Email: ";
        cin >> c.email;
        cout << "Phone: ";
        cin >> c.phone;
        contacts.push_back(c);
        cout << "Contact successfully added..";
    }
    void viewContacts() {
        cout << "All saved contacts: " << endl;
        for(Contact c : contacts) {
            cout << setw(10) << c.name << "|" << setw(10) << c.phone << "|" << setw(10) << c.email << endl;
        }
    }
    void searchContact() {
        string p;
        cout << "Enter phone no. for details: " << endl;
        cout << "Phone: ";
        cin >> p;
        for(int i = 0; i < contacts.size(); i++) {
            if(p.compare(contacts[i].phone) == 0) {
                contacts[i].display();
                return;
            }
        }
        cout << "Contact not found";
    }
    void deleteContact() {
        string p;
        cout << "Enter phone no. to delete Contact: " << endl;
        cout << "Phone: ";
        cin >> p;
        int cnt = -1;
        for(int i = 0; i < contacts.size(); i++) {
            if(p.compare(contacts[i].phone) == 0) {
                cnt = i;
                break;
            }
        }
        if(cnt == -1) {
            cout <<"Contact not found" << endl;
        } else {
            contacts.erase(contacts.begin() + cnt);
            cout << "Contact deleted successfully!" << endl;
        }
    }
    void updateContact() {
        string p;
        string n;
        string e;
        cout << "Enter phone no. of Contact to update:" << endl;
        cout << "Phone: ";
        cin >> p;
        for(int i = 0; i < contacts.size(); i++){
            if(p.compare(contacts[i].phone) == 0) {
                cout << "Updated name: ";
                cin >> n;
                cout << "Updated email: ";
                cin >> e;
                contacts[i].name = n;
                contacts[i].email = e;
                cout << "Updated Details: " << endl;
                contacts[i].display();
                return;
            }
        }
        cout << "Contact not found" << endl;
    }
    void savetoFile() {
        ofstream out("Contact.txt");
        for(int i = 0; i < contacts.size(); i++) {
            out << contacts[i].name <<"|"<< contacts[i].phone <<"|"<< contacts[i].email << endl; 
        }
        cout << "All contacts saved" << endl;
        out.close();
    }
    void loadFile() {
        ifstream in("Contact.txt");
        if (!in) {
            ofstream createFile("Contact.txt");
            createFile.close();

            cout << "Contact file not found. Creating a new one...\n";
            return;
        }
        string line;
        while(getline(in, line)) {
            stringstream ss(line);
            string n, p, e;
            getline(ss, n, '|');
            getline(ss, p, '|');
            getline(ss, e);
            contacts.push_back(Contact(n, p, e));
        }
        cout << "Loaded all contacts from file" << endl;
        in.close();
    }
};

int main() {
    ContactManager contact;
    contact.loadFile();
    int choice;

    bool loop = true;
    while(loop) {
        cout << "===== Contact Manager =====" << endl;
        cout << "1. Add Contact" << endl; 
        cout << "2. View All Contacts" << endl; 
        cout << "3. Search Contact" << endl; 
        cout << "4. Delete Contact" << endl; 
        cout << "5. Update Contact" << endl; 
        cout << "6. Exit" << endl; 
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                contact.addContact();
                break;

            case 2:
                contact.viewContacts();
                break;

            case 3:
                contact.searchContact();
                break;
            case 4:
                contact.deleteContact();
                break;
            case 5:
                contact.updateContact();
                break;

            case 6:
                contact.savetoFile();
                loop = false;
                break;

            default:
                cout << "Invalid choice enter again" << endl;
                break;
        }
    }
    cout << "====== EXIT ======"; 
    return 0;
}