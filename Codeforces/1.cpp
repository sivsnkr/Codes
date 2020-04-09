#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int exams;
    cin >> exams;

    vector<pair<int, int>> exams_date(exams);

    int i;
    for (i = 0; i < exams; i++)
    {
        int main, pre;
        cin >> main >> pre;
        exams_date[i] = {main, pre};
    }

    sort(exams_date.begin(), exams_date.end());

    int prev_exam_date = min(exams_date[0].second, exams_date[0].first);
    int date_no;
    for (i = 1; i < exams; i++)
    {
        if (prev_exam_date > exams_date[i].second)
        {
            prev_exam_date = exams_date[i].first;
        }
        else
        {
            prev_exam_date = max(prev_exam_date, exams_date[i].second);
        }
    }

    cout << prev_exam_date;
    cout << "\n";
}