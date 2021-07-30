#include <bits/stdc++.h>
using namespace std;
#define NL '\n'
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

// aaram se code kro, nhi to bhoot glti hoga
// hm to khenge ki, step by step bdho or dhyan se kro

class HangmanHelper {
  public:
  string show(string secretWord, string lettersGuessed) {
      
  }
};
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string secretWord         = "SECRET";
			string lettersGuessed     = "";
			string expected__         = "______";

			std::clock_t start__      = std::clock();
			string received__         = HangmanHelper().show(secretWord, lettersGuessed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string secretWord         = "SECRET";
			string lettersGuessed     = "CAE";
			string expected__         = "_EC_E_";

			std::clock_t start__      = std::clock();
			string received__         = HangmanHelper().show(secretWord, lettersGuessed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string secretWord         = "REVEALED";
			string lettersGuessed     = "QWERTYUIOPASDFGHJKLZXCVBNM";
			string expected__         = "REVEALED";

			std::clock_t start__      = std::clock();
			string received__         = HangmanHelper().show(secretWord, lettersGuessed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string secretWord         = "ALONGEREXAMPLE";
			string lettersGuessed     = "SOMETHING";
			string expected__         = "__ONGE_E__M__E";

			std::clock_t start__      = std::clock();
			string received__         = HangmanHelper().show(secretWord, lettersGuessed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string secretWord         = ;
			string lettersGuessed     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = HangmanHelper().show(secretWord, lettersGuessed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string secretWord         = ;
			string lettersGuessed     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = HangmanHelper().show(secretWord, lettersGuessed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string secretWord         = ;
			string lettersGuessed     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = HangmanHelper().show(secretWord, lettersGuessed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
