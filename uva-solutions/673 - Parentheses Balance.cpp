#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	getc(stdin);

	while (n--) {
		stack<char> S;
		char s[140];
		gets(s);

		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (s[i] == '(' || s[i] == '[') {
				S.push(s[i]);
			} else if (s[i] == ')') {
				if (S.empty() || S.top() != '('){
					S.push('a');
					break;
				}
				S.pop();
			} else if (s[i] == ']') {
				if (S.empty() || S.top() != '['){
					S.push('a');
					break;
				}
				S.pop();
			}
		}

		if(S.empty()) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}