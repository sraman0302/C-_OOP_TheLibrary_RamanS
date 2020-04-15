#include "Graduate.h"
string Graduate::get_gradname() { return name; }
void Graduate::grad_display() {
  ifstream input_file;
  string book;
  input_file.open("members.txt");
  if (input_file) {
    while (input_file >> id >> name >> age >> book) {
      if (id >= 5000) {
        cout << id << '\t' << name << '\t' << age << '\t' << book << '\n';
        gradmem.push_back(name);
      } else {
        continue;
      }
    }
    input_file.close();
  }
}

void Graduate::edit_grad() {
  int getid, found = 0, n = 0, i, pos;
  vector<string> books;
  vector<string> names;
  vector<int> ages;
  vector<int> all_ID;
  cout << "Enter ID of Graduate student:";
  cin >> getid;
  ifstream input_file;
  string book;
  input_file.open("members.txt");
  if (input_file) {
    while (input_file >> id >> name >> age >> book) {
      all_ID.push_back(id);
      if (getid == id) {
        pos = n;
        found = 1;

        books.push_back(book);
        names.push_back(name);
        ages.push_back(age);
        n++;
      }
    }

    if (found == 1) {
      cout << "Do you want to edit your name?(y/n)";
      char ch;
      cin >> ch;
      if (ch == 'y') {
        cout << "Enter new name: ";
        cin >> names[pos];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else {
        cout << endl;
      }
      cout << "Do you want to edit your age?(y/n)";

      cin >> ch;
      if (ch == 'y') {
        cout << "\nEnter new age:";
        cin >> ages[pos];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else {
        cout << endl;
      }
    } else {
      cout << "Member not found";
    }
  }

  input_file.close();
  ofstream up_file;
  up_file.open("members.txt");
  for (i = 0; i < n; i++) {
    up_file << all_ID[i];
    up_file << names[i];
    up_file << ages[i];
    up_file << books[i];
    up_file << endl;
  }
  up_file.close();
}
void Graduate::remove_gradmember() {
  int getid, found = 0, n = 0, i, pos;
  vector<string> books;
  vector<string> names;
  vector<int> ages;
  vector<int> all_ID;
  cout << "Enter ID of Graduate studentto be deleted:";
  cin >> getid;
  ifstream input_file;
  string book;
  input_file.open("members.txt");
  if (input_file) {
    while (input_file >> id >> name >> age >> book) {
      all_ID.push_back(id);
      if (getid == id) {
        pos = n;
        found = 1;

        books.push_back(book);
        names.push_back(name);
        ages.push_back(age);
        n++;
      }
    }

    if (found == 1) {
      books.erase(books.begin() + pos);
      names.erase(names.begin() + pos);
      ages.erase(ages.begin() + pos);
      all_ID.erase(all_ID.begin() + pos);

    } else {
      cout << "Member not found" << endl;
    }
  }

  input_file.close();
  ofstream up_file;
  up_file.open("members.txt");
  for (i = 0; i < n; i++) {
    up_file << all_ID[i];
    up_file << names[i];
    up_file << ages[i];
    up_file << books[i];
    up_file << endl;
  }
  up_file.close();
}