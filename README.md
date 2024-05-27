# Extra Task
Objektinio programavimo egzamino (išankstinė) užduotis. Sukurta programa galinti suskaičiuoti kiek kartų tekste pasikartoja žodžiai. Taip pat ji išrenka visas internetines nuorodas ir duomenis išveda i lentelę.

# Code preview
## 1. `ReadFile`
```cpp
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
```
## 2. `ReadLink`
```cpp
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
```
# Files

## `input1.txt`
Tekstas paimtas iš google scholar be nuorodų.
## `input2.txt`
Tekstas paimtas iš google scholar be su nuorodomis.
## `main.cpp`
Pagrindinis programos failas.
## `header.h`
Antraštinis failas.
