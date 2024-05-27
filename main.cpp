#include "header.h"

using namespace std;

int main() {
   string BasicInput = "Input1.txt"; // Input with no links
   string LinkInput = "Input2.txt"; // Input with links

   map<string, Data> Info;
   map<int, string> Links;

   ReadFile(BasicInput, Info);
   ReadLink(LinkInput, Links);

   cout << "File reading and word counting has been done!" << endl;
   
   system("pause");
}

// Funtion for reading files and counting words
void ReadFile(string filename, map<string, Data>& map) {
   ifstream file;
   string word;
   int n = 1;

   file.open(filename);

   while(getline(file, word)) {
      vector<string> Line = cleanline(word);

      for (string& word : Line) {
         map[word].number++;
         map[word].lines.insert(n);
      }
      n++;
   }

   Output(map);
   CrossReferenceTable(map);

   file.close();
}

// Function for reading files and searching for links
void ReadLink(string filename, map<int, string>& map) {
   ifstream file;
   string link;
   int n = 0;

   file.open(filename);

   while(getline(file, link)) {
      vector<string> Line = getLink(link);

      for (string& url : Line) {
         map[n++] = url;
      }
   }

   printLink(map);

   file.close();
}

// Takes the lines and removes any punctuations
vector<string> cleanline(string& line) {
   vector<string> cleanWord;
   string word;
   size_t found = line.find_first_of(",.!:;?'()[]{}…’–"); // Types of the punctuation to remove

   while (found != string::npos) {
      line.erase(found, 1);
      found = line.find_first_of(",.!:;?'()[]{}…’–", found + 1);
   }

   line.erase(remove(line.begin(), line.end(), '"'), line.end());

   istringstream Line(line);

   while (Line >> word) {
      cleanWord.push_back(word);
   }

   return cleanWord;
}

// Function that find the string with a link
vector<string> getLink(string& line) {
   vector<string> link;
   string word;
   size_t found = line.find("http");
   istringstream Line(line);

   while (Line >> word) {
      if (word.find("http") != string::npos) {
         link.push_back(word);
      }
   }

   return link;
}

// Function for printing out words
void Output(map<string, Data>& map) {
   ofstream output;

   output.open("Word_Counter.txt");

   for (const auto &duom : map) {
      if (duom.second.number > 1) {
         output << duom.first << ", " << duom.second.number << endl;
      }
   }

   output.close();
   cout << "Words have been counted and results been writen to the file: Word_Counter.txt" << endl;
}

// Function for printing found links
void printLink(map<int, string>& map) {
   ofstream write;

   write.open("Link_List.txt");

   for (const auto &duom : map) {
      write << duom.first + 1 << ". " << duom.second << endl;
   }

   write.close();
   cout << "Links have been found and writen to the file: Link_List.txt" << endl;
}

// Function to output words in a cross reference type table
void CrossReferenceTable(map<string, Data>& map) {
   ofstream output;

   output.open("Output_Table.txt");

   output << left << setw(20) << "Word" << "| " << setw(51) << "Line" << endl;
   output << "-----------------------------------------------------------------------" << endl;

   for (const auto &duom : map) {
      const string& word = duom.first;
      const Data& data = duom.second;

      if (data.number > 1) {
         output << left << setw(20) << word << "|";

         for (int line : data.lines) {
            output << line << ", ";
         }
         output << endl;
         output << "--------------------|--------------------------------------------------" << endl;
      }
   }
   output.close();
   cout << "Cross-reference table has been generated and writen to the file: Output_Table.txt" << endl;
}