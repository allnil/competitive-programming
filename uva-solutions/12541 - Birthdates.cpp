#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Person
{
  char name[20];
  int day;
  int month;
  int year;
};

bool compareTwoDate(Person a, Person b) {
  if (a.year != b.year) {
    return a.year > b.year;
  }

  if (a.month != b.month) {
    return a.month > b.month;
  }

  return a.day > b.day;
}


int main() {
  int n; scanf("%d", &n);

  vector<Person> pp;pp.reserve(100);

  while(n--){
    Person p;
    scanf("%s %d %d %d", p.name, &p.day, &p.month, &p.year);
    pp.push_back(p);
  }

  sort(pp.begin(), pp.end(), compareTwoDate);
 
  printf("%s\n", pp[0].name);
  printf("%s\n", pp[pp.size()-1].name);

  return 0;
}