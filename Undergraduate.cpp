#include "Undergraduate.h"
string Undergraduate::get_stdname() { return name; }
void Undergraduate::stddisplay() {
  ifstream input_file;
  input_file.open("Members.txt");

  // Display Format
  cout << "***********************************************" << endl;
  cout << "ID\tSTUDENT NAME\tAGE\tBook Borrowed" << endl;
  cout << "***********************************************" << endl;
  if (input_file) {
    while (!input_file.eof()) {
      getline(input_file, name, '\t');
      getline(input_file, book, '\t');
      input_file >> id >> age;
      if (id <= 4999) {
        cout << left << setw(8) << id << left << setw(18) << name << left
             << setw(7) << age << left << setw(10) << book;
        cout << "\n---------------------------------------------" << endl;
      } else {
        continue;
      }
    }
    input_file.close();
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
}

void Undergraduate::edit_std() {
  int getid, edch;
  char ch;
  ofstream temp_file;
  temp_file.open("Temp.txt");
  bool filecheck, found = false;

  ifstream input_file;
  input_file.open("Members.txt");

  cout << "Enter ID of UNDERGRADUATE student:";
  cin >> getid;
  if (getid >= 5000) {
    cout << "Incorrect Menu Section" << endl;
  }

  if (input_file) {
    if (temp_file) {
      filecheck = true;
    }
  }

  if (filecheck) {
    while (!input_file.eof()) {
      getline(input_file, name, '\t');
      getline(input_file, book, '\t');
      input_file >> id >> age;
      if ((getid == id) && (getid <= 4999)) {
        found = true;
        cout << "User " << id << "\nName: " << name
             << "\nFound. Do you want to edit their record?(y/n): ";
        cin >> ch;
        if (ch == 'y') {
          cout << "Edit Menu" << endl;
          cout << "1.Edit Name" << endl;
          cout << "2.Edit Age" << endl;
          cout << "3. Exit" << endl;

          cout << "Your choice: ";
          cin >> edch;
          switch (edch) {
            case 1:
              cin.ignore(numeric_limits<streamsize>::max(), '\n');

              cout << "\nEnter New Name";
              getline(cin, name, '\n');

              cout << "\nName Updated" << endl;

              break;
            case 2:
              cout << "\nEnter New Age";
              cin >> age;
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cout << "Age Update Successfully" << endl;
              break;
            case 3:
              break;
            default:
              cout << "Incorrect Option" << endl;
              break;
          }
        } else if (ch == 'n') {
          cout << "User Record not Edited" << endl;
        } else {
          cout << "Error. User not Found or incorrect user entry." << endl;
        }
      }
      temp_file << name;
      temp_file << "\t";
      temp_file << book;
      temp_file << "\t";

      temp_file << id;
      temp_file << " ";

      temp_file << age;
    }
    input_file.close();
    temp_file.close();
    remove("Members.txt");
    rename("Temp.txt", "Members.txt");
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
  if (!found) {
    cout << "Record not Found." << endl;
  }
}
void Undergraduate::remove_member() {
  int getid;
  bool found = false;
  ofstream temp_file;
  temp_file.open("Temp.txt");
  cout << "Enter ID of undergraduate student to be deleted:";
  cin >> getid;
  ifstream input_file;
  if (getid >= 5000) {
    cout << "Incorrect Section" << endl;
  }

  input_file.open("Members.txt");
  if (input_file && temp_file) {
    while (!input_file.eof()) {
      getline(input_file, name, '\t');
      getline(input_file, book, '\t');
      input_file >> id >> age;
      char ch = 'n';
      if ((getid == id) && (getid <= 4999)) {
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
        temp_file << name;
        temp_file << "\t";
        temp_file << book;
        temp_file << "\t";

        temp_file << id;
        temp_file << " ";

        temp_file << age;
      }
    }
    input_file.close();
    temp_file.close();
    remove("Members.txt");
    rename("Temp.txt", "Members.txt");
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }

  if (!found) {
    cout << "Record Not Found" << endl;
  }
}