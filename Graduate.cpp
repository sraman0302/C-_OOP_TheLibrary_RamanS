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
  vector<string> books;
  vector<string> names;
  vector<int> ages;
  vector<int> all_ID;
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
      all_ID.push_back(id);
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
      }
      books.push_back(book);
      names.push_back(name);
      ages.push_back(age);
      n++;
    }
  }

  input_file.close();
  ofstream up_file;
  up_file.open("Members.txt");
  for (i = 0; i < n; i++) {
    up_file << all_ID[i];
    up_file << " ";
    up_file << names[i];
    up_file << " ";
    up_file << ages[i];
    up_file << " ";
    up_file << books[i];

    up_file << endl;
  }
  up_file.close();
}
void Graduate::remove_gradmember() {
  int getid, n = 0, i;
  bool found = false;
  vector<string> books;
  vector<string> names;
  vector<int> ages;
  vector<int> all_ID;
  cout << "Enter ID of Graduate student to be deleted:";
  cin >> getid;
  ifstream input_file;
  string book;
  if (getid <= 5000) {
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
        all_ID.push_back(id);
        books.push_back(book);
        names.push_back(name);
        ages.push_back(age);
        n++;
      }
    }
  }

  input_file.close();
  if (!found) {
    cout << "Record Not Found" << endl;
  }
  ofstream up_file;
  up_file.open("Members.txt");
  for (i = 0; i < n; i++) {
    up_file << all_ID[i];
    up_file << " ";
    up_file << names[i];
    up_file << " ";
    up_file << ages[i];
    up_file << " ";
    up_file << books[i];

    up_file << endl;
  }
  up_file.close();
}