#include "Member.h"
// rand() % (b - a + 1) + a
int Member::count = 0;
int Member::member_count() { return count; }

string Member::get_name() { return name; }
void Member::set_ID() {
  srand(time(nullptr));

  while (true) {
    cout << "Are you an undergraduate student (y/n): ";
    char ch;
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
      if (ch == 'y') {
        id = rand() % 4000 + 1000;

      } else if (ch == 'n') {
        id = rand() % 5000 + 5000;

      } else {
        cout << "Invalid Choice.";
        id = 0;
        break;
      }
      int i, found = 0, n = membersID.size();

      for (i = 0; i < n; i++) {
        if (id == membersID[i]) {
          found = 1;
        }
      }
      if (found == 0 || membersID.size() == 0) {
        break;
      }
    }
    break;
  }
}
void Member::display() {
  ifstream input_file;
  input_file.open("Members.txt");
  string book;
  cout << "===============================================" << endl;
  cout << "ID\tSTUDENT NAME\t AGE\tBook Borrowed" << endl;
  cout << "===============================================" << endl;
  if (input_file) {
    while (!input_file.eof()) {
      getline(input_file, name, '\t');
      getline(input_file, book, '\t');
      input_file >> id >> age;
      cout << left << setw(8) << id << left << setw(18) << name << left
           << setw(7) << age << left << setw(10) << book;
      cout << endl;
    }
    input_file.close();
  } else {
    cout << "Error" << endl;
  }
}
void Member::input() {
  ++count;
  ofstream ofile;
  ofile.open("Members.txt", ios::app);
  if (ofile) {
    set_ID();
    if (id != 0) {
      cout << "Unique ID Code: " << id << endl;

      cout << "Enter your name:";
      getline(cin, name);
      // cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "\nEnter age: ";
      cin >> age;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      ofile << name;
      ofile << "\t";
      ofile << "Nill\t";
      ofile << id;
      ofile << " ";
      ofile << age;
      // ofile << "\n";

      ofile.close();
    } else {
      cout << "\nMember cannot be input" << endl;
    }
  } else {
    cout << "Error" << endl;
    ofile.close();
  }
}
vector<int> Member::operator+(const Member& member) {
  ifstream input_file;
  string book;
  input_file.open("Members.txt");
  if (input_file) {
    while (!input_file.eof()) {
      getline(input_file, name, '\t');
      getline(input_file, book, '\t');
      input_file >> id >> age;
      membersID.push_back(id);
    }
  }
  return membersID;
}
