#include "Graduate.h"
void Graduate::grad_display() {
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
      if (id > 4999) {
        cout << left << setw(8) << id << left << setw(18) << name << left
             << setw(7) << age << left << setw(10) << book;
        cout << "\n---------------------------------------------" << endl;
      } else {  // Skip Iteration
        continue;
      }
    }
    input_file.close();
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
}

void Graduate::edit_grad() {
  int getid,
      edch;  // Variables used for ID search and edch for Edit Menu Choice.
  char ch;
  // Temp File created to store all data

  ofstream temp_file;
  temp_file.open("Temp.txt");

  // Current File Opened

  ifstream input_file;
  input_file.open("Members.txt");

  bool filecheck, found = false;

  cout << "Enter ID of GRADUATE student:";
  cin >> getid;
  if (getid < 5000) {
    cout << "Incorrect Menu Section" << endl;
  }
  // Check File Status

  if (input_file) {
    if (temp_file) {
      filecheck = true;
    }
  }

  if (filecheck) {
    while (!input_file.eof()) {
      // Retrieve Prior Information

      getline(input_file, name, '\t');
      getline(input_file, book, '\t');
      input_file >> id >> age;
      // If ID is matched

      if ((getid == id) && (getid >= 5000)) {
        found = true;
        cout << "User " << id << "\nName: " << name
             << "\nFound. Do you want to edit their record?(y/n): ";
        cin >> ch;  // Reinstate Edit Choice
        ch = towlower(ch);
        if (ch == 'y') {
          // Edit Menu Display

          cout << "Edit Menu" << endl;
          cout << "1.Edit Name" << endl;
          cout << "2.Edit Age" << endl;
          cout << "3. Exit" << endl;

          cout << "Your choice: ";
          cin >> edch;
          // Switch Statement to run the Menu Choice

          switch (edch) {
            case 1:
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              // New Name Entry

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
        } else {  // If User Enter's Other Choice
          cout << "Error. User not Found or incorrect user entry." << endl;
        }
      }
      // Store All Prior Data Regardless ID Found

      temp_file << name;
      temp_file << "\t";
      temp_file << book;
      temp_file << "\t";

      temp_file << id;
      temp_file << " ";

      temp_file << age;
    }
    // Both Files Closed

    input_file.close();
    temp_file.close();
    // Rename Temp File as it holds the Edit Made and Remove Previous Member
    // File without the Edit
    remove("Members.txt");
    rename("Temp.txt", "Members.txt");
    if (!found) {
      cout << "Record not Found." << endl;
    }
  } else {
    throw runtime_error("\nError! Unable to open Essential files\n ");
  }
}
void Graduate::remove_gradmember() {
  int getid;
  bool found = false;
  ofstream temp_file;
  temp_file.open("Temp.txt");
  cout << "Enter ID of undergraduate student to be deleted:";
  cin >> getid;
  ifstream input_file;
  string book;
  if (getid < 5000) {
    cout << "Incorrect Section" << endl;
  }  // If User makes Incorrect Entry

  input_file.open("Members.txt");
  if (input_file) {
    while (!input_file.eof()) {
      getline(input_file, name, '\t');
      getline(input_file, book, '\t');
      input_file >> id >> age;
      char ch = 'n';

      // If ID Matches

      if ((getid == id) && (getid >= 5000)) {
        cout << "User " << id << "\nName: " << name
             << "\nFound.\nDo you want to Erase their record?\nThis process "
                "cannot "
                "be reversed(y/n): ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ch = tolower(ch);
      }
      if (ch == 'y') {
        cout << "Record Erased" << endl;
        found = true;
        continue;  // Goes to next Iteration
      } else {     // As ch is set to 'n' the file would be transfered to Temp
                   // regardless Found
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