#include "stdio.h"
#include <stack>

using namespace std;

int main()
{
	int n, in;
  
	while (scanf("%d", &n)){
    if (n == 0) {
      break;
    }

	  while (scanf("%d", &in)){
      if(in == 0) {
        break;
      }
			bool success = true;
			stack<int> station, A;

			for (int i = n; i > 0; --i) A.emplace(i);
			for (int i = 0; i < n; ++i) {
				if (i) scanf("%d", &in);
				if (!station.empty() && station.top() == in) station.pop();
				else {
					while (!A.empty() && A.top() != in) station.emplace(A.top()), A.pop();
					if (A.empty()) success = false;
					else A.pop();
				}
			}

			printf(success ? "Yes\n" : "No\n");
		}
		printf("\n");
	}
	return 0;
}
