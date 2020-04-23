#include "Graduate.h"
string Graduate::get_gradname() { return name; }
void Graduate::grad_display() {
  ifstream input_file;
  string book;
  input_file.open("Members.txt");
  cout << "ID\tSTUDENT NAME\tAGE\tBook Borrowed" << endl;
  if (input_file) {
    while (input_file >> id >> name >> age >> book) {
      if (id > 4999) {
        cout << id << '\t' << name << '\t' << age << '\t' << book << '\n';
      } else {
        continue;
      }
    }
    input_file.close();
  }
}

void Graduate::edit_grad() {
  int getid, n = 0, i;
  char ch;
  ofstream temp_file;
  temp_file.open("Temp.txt");

  cout << "Enter ID of Graduate student:";
  cin >> getid;
  if (getid < 5000) {
    cout << "Incorrect Menu Section" << endl;
  }
  ifstream input_file;
  string book;
  input_file.open("Members.txt");
  if (input_file) {
    while (input_file >> id >> name >> age >> book) {
      if ((getid == id) && (getid >= 5000)) {
        cout << "User " << id << "\nName: " << name
             << "\nFound. Do you want to edit their record?(y/n): ";
        cin >> ch;
        if (ch == 'y') {
          cout << "Do you want to edit your name?(y/n)";
          cin >> ch;
          if (ch == 'y') {
            cout << "Enter new name: ";
            cin >> name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } else {
            cout << endl;
          }
          cout << "Do you want to edit your age?(y/n)";

          cin >> ch;
          if (ch == 'y') {
            cout << "\nEnter new age:";
            cin >> age;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
          } else {
            cout << endl;
          }
          cout << "Name:" << name << "\nAge: " << age
               << "\nRecord Updated successfully" << endl;
        } else if (ch == 'n') {
          cout << "User Record not Edited" << endl;
        } else {
          cout << "Error. User not Found or incorrect user entry." << endl;
        }
        temp_file << id;
        temp_file << " ";
        temp_file << name;
        temp_file << " ";

        temp_file << age;
        temp_file << " ";

        temp_file << book;
        temp_file << endl;
        n++;
      }
    }

    input_file.close();
    temp_file.close();
    remove("Members.txt");
    rename("Temp.txt", "Members.txt");
  }
}
void Graduate::remove_gradmember() {
  int getid, n = 0, i;
  bool found = false;
  ofstream temp_file;
  temp_file.open("Temp.txt");
  cout << "Enter ID of undergraduate student to be deleted:";
  cin >> getid;
  ifstream input_file;
  string book;
  if (getid < 5000) {
    cout << "Incorrect Section" << endl;
  }

  input_file.open("Members.txt");
  if (input_file) {
    while (input_file >> id >> name >> age >> book) {
      char ch = 'n';
      if ((getid == id) && (getid >= 5000)) {
        cout << "User " << id << "\nName: " << name
             << "\nFound.\nDo you want to Erase their record?\nThis process "
                "cannot "
                "be reversed(y/n): ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      if (ch == 'y') {
        cout << "Record Erased" << endl;
        found = true;
        continue;
      } else {
        temp_file << id;
        temp_file << " ";
        temp_file << name;
        temp_file << " ";

        temp_file << age;
        temp_file << " ";

        temp_file << book;
        temp_file << endl;
        n++;
      }
    }
  }

  input_file.close();
  temp_file.close();
  if (!found) {
    cout << "Record Not Found" << endl;
  }
  remove("Members.txt");
  rename("Temp.txt", "Members.txt");
}