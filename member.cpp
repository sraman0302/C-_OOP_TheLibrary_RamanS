#include "Member.h"
// Member Option Input
int Member::count = 0;  // Static Variable Declaration in Class

void Member::input() {
  // Member File opened in Append Mode
  ofstream ofile;
  ofile.open("Members.txt", ios::app);

  if (ofile) {
    set_ID();       // ID is set
    if (id != 0) {  // ID will be 0 if user does not make an appropriate entry.
                    // For example, (y/n) entries made wrong

      cout << "Unique ID Code: " << id << endl;

      cout << "Enter your name:";
      getline(cin, name);

      cout << "\nEnter age: ";
      cin >> age;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // Entered Info sent to Members file
      ofile << name;
      ofile << "\t";
      ofile << "Nill\t";
      ofile << id;
      ofile << " ";
      ofile << age;

      ++count;  // Increment Static Variable. An increment indicates a new
                // member added in a successful run
    } else {
      cout << "\nMember cannot be input" << endl;
    }
    ofile.close();
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
}

void Member::set_ID() {
  srand(time(nullptr));

  while (true) {
    // Operator Overloading used to create a vector of previous ID's to avoid a
    // duplication situation
    Member m1, m2;
    vector<int> ID_check;
    ID_check = m1 + m2;

    cout << "Are you an undergraduate/graduate student(u / g): ";
    char ch;
    cin >> ch;
    ch = towlower(ch);  // Avoid Case Sensitivity issues.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
      if (ch == 'u') {
        id = rand() % 4000 + 1000;  // UG Students to hold range 1000-4999

      } else if (ch == 'g') {
        id = rand() % 5000 + 5000;  // Grad Students to hold range 5000-9999

      } else {
        cout << "Invalid Choice. u/g only";
        id = 0;  // Set ID to zero to avoid entering ID to file
        break;
      }
      int i, found = 0, n = ID_check.size();

      for (i = 0; i < n; i++) {
        if (id == ID_check[i]) {
          found = 1;  // As set to 1, the loop re-runs later
        }
      }
      if (found == 0 || n == 0) {
        break;  // Loops out only if the ID is unique
      }
    }
    break;
  }
}
void Member::display() {
  ifstream input_file;
  input_file.open("Members.txt");

  // Display Format
  cout << "===============================================" << endl;
  cout << "ID\tSTUDENT NAME\t AGE\tBook Borrowed" << endl;
  cout << "===============================================" << endl;

  if (input_file) {
    while (!input_file.eof()) {
      // Retrieve Prior Information from .txt File
      getline(input_file, name, '\t');
      getline(input_file, book, '\t');
      input_file >> id >> age;

      // Adequate Spacing being made for better Tabular Representation
      cout << left << setw(8) << id << left << setw(18) << name << left
           << setw(7) << age << left << setw(10) << book;
      cout << "\n---------------------------------------------" << endl;
    }
    input_file.close();
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
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
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
  return membersID;
}
string Member::get_name() { return name; }  // Returns Name
int Member::member_count() {
  return count;
}  // Returns Static Variable when Required
