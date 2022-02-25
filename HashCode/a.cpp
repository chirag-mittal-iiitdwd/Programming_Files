#include <bits/stdc++.h>
using namespace std;

class Person{
    public:
    string name;
    vector<pair<string,int>>skills;
    Person(pair<string,int>p){
        skills.push_back(p);
    }
    Person(string n){
        name=n;
    }
};

class Project{
    public:
    string name;
    int duration;
    int points;
    int deadline;
    int roles;
    bool isCompleted;
    vector<pair<string,int>>skills;
    Project(string n,int d,int p,int dead,int role){
        name=n;
        duration=d;
        points=p;
        deadline=dead;
        roles=role;
        isCompleted=false;
    }
};

class Out{
    public:
    string projectName;
    vector<string>contris;
};

static bool comp(Project p1,Project p2){
    return p1.deadline<p2.deadline;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("Input/input.txt",  "r",  stdin);
        freopen("Out/output.txt", "w", stdout);
    #endif
    
    int c,p;
    cin>>c>>p;
    vector<Person>contri;
    vector<Project>proj;
    for(int i=0;i<c;i++){
        string name;
        int skills;
        cin>>name;
        cin>>skills;
        Person per(name);
        for(int j=0;j<skills;j++){
            string skillName;
            cin>>skillName;
            int level;
            cin>>level;
            per.skills.push_back({skillName,level});
        }
        contri.push_back(per);
    }

    for(int i=0;i<p;i++){
        string projName;
        int duration,points,deadline,roles;
        cin>>projName>>duration>>points>>deadline>>roles;
        Project pro(projName,duration,points,deadline,roles);
        for(int j=0;j<roles;j++){
            string skill;
            int level;
            cin>>skill>>level;
            pro.skills.push_back({skill,level});
        }
        proj.push_back(pro);
    }

    sort(proj.begin(),proj.end(),comp);
    
    vector<Out>ans;
    for(int i=0;i<p;i++){

    }
    
	return 0;
}