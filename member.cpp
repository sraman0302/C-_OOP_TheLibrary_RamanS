#include "Member.h"
// rand() % (b - a + 1) + a
int Member::count = 0;

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
  if (input_file.is_open()) {
    cout << "Dis ";
    while (input_file >> id >> name >> age) {
      cout << id << '\t' << name << '\t' << age << '\n';
    }
    input_file.close();
  }
}

void Member::input() {
  ++count;
  ofstream ofile;
  ofile.open("Members.txt", ios::app);
  if (ofile) {
    cout << "Hi";
    set_ID();
    cout << "Unique ID Code" << id << endl;
    ofile << id;
    cout << "Enter your name:";
    cin >> name;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ofile << name;
    cout << "Enter age";
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ofile << age;
    ofile << " ";
    ofile << endl;
    ofile.close();
  } else {
    cout << "Error" << endl;
    ofile.close();
  }
}
vector<int> Member::operator+(const Member& member) {
  ifstream input_file;
  int ID;
  input_file.open("members.txt");
  if (input_file) {
    while (input_file >> ID) {
      membersID.push_back(ID);
    }
  }
  return membersID;
}
int Member::member_count() { return count; }