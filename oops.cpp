#include<bits/stdc++.h>

using namespace std;

class Entity{
	public:
		string GetName(){return "Entity";}
};

class Player : public Entity{
	private:
		string m_Name;
	public:
		Player(const string &name):m_Name(name){}
		string GetName(){return m_Name;}
};

int main(){
	Entity* e = new Entity();
	cout<<e->GetName()<<endl;
	Player* p = new Player("Cherno");
	cout<<p->GetName()<<endl;

	return 0;
}