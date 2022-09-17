#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;
using int64 = int64_t;

typedef struct _syn {
    string list_id;
    vector<string> list_report;
    vector<string> list_preport;
    int64 list_reported_num;
    int64 receive_mail;
} syn;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> id_map;
    syn p[200002];

    int64 id_list_num = 0;
    for (auto id_list_iter = id_list.begin(); id_list_iter < id_list.end();) {
        id_map[*id_list_iter] = id_list_num;
        p[id_list_num].list_id = *id_list_iter;
        id_list_num += 1;
        ++id_list_iter;
    }

    vector<string> v;
    for (auto report_iter = report.begin(); report_iter < report.end();) {
        string strBuffer;
        strBuffer = *report_iter;
        istringstream ss(strBuffer);

        while (getline(ss, strBuffer, ' ')) {
            v.push_back(strBuffer);
        }
        ++report_iter;
    }

    string reporter, preporter;
    for (auto v_iter = v.begin(); v_iter < --v.end();) {
        reporter = *v_iter;
        ++v_iter;
        preporter = *v_iter;
        ++v_iter;
        int64 i = id_map[reporter];
        int64 j = id_map[preporter];
        if (find(p[i].list_report.begin(), p[i].list_report.end(), preporter) == p[i].list_report.end()) {
            p[i].list_report.push_back(preporter);
            p[j].list_preport.push_back(reporter);
            p[j].list_reported_num += 1;
        }
    }

    for (int64 i = 0; i < id_list_num;) {
        if (p[i].list_reported_num >= k) {
            for (auto list_preport_iter = p[i].list_preport.begin(); list_preport_iter < p[i].list_preport.end();) {
                p[id_map[*list_preport_iter]].receive_mail += 1;
                ++list_preport_iter;
            }
        }
        ++i;
    }

    for (int64 i = 0; i < id_list_num;) {
        answer.push_back(p[i].receive_mail);
        ++i;
    }

    return answer;
}