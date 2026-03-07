#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<vector>

using namespace std;


class Equipment{
    int hpmax;
    int atk;
    int def;
    int spd;
    public:
        Equipment(int,int,int,int);
        vector<int> getStat();            
};

Equipment::Equipment(int h, int a, int d,int s){
    hpmax = h;
    atk = a;
    def = d;
    spd = s;
}

vector<int> Equipment::getStat(){
    vector<int> stat;
    stat.push_back(hpmax);
    stat.push_back(atk);
    stat.push_back(def);
    stat.push_back(spd);
    return stat;
}

class Unit{
		string name;
		string type;		
		int hp;
		int hpmax;
		int atk;
	    int def;
        int hppart_head;

        int hppart_left_hand;
        int hppart_right_hand;
        int hppart_left_leg;
        int hppart_right_leg;
        int spd;
        bool guard_on;
        bool dodge_on;	
        int exp;
        int lvl;
        Equipment *equipment;	
        bool part2atk;	
        int hbb;
        int Hbb;	
	public:			
		void create(string);
        Unit(string,string);
		void showStatus();
        void newTurn();
		void personTurn();
        int spd_t;
		int attack(Unit &,string);
		int beAttacked(int,string);
		int heal(Unit &);
        int beheal(int);
        int buffatk();
        int buffdef();	
        int lvlup();
        void upgrade();
        void downgrade();
		void guard();
        void dodge();
		bool isDead();	
        void equip(Equipment *);
        void set_death();
        void spawn();
        void setlvl(int);
        void expp(int);
        void Hbk();
        void hbk();
        void endoturn();
        void setloom();
};

Unit::Unit(string t,string n){ 
    type = t;
    name = n;
    if(type == "Maincha1"){
        lvl =1;
        hpmax = 60;
        atk = 10;
        def = 10;
        spd =10;
        exp=0;
        hbb=0;
        Hbb=0;
    }else if(type == "Maincha2"){
        lvl =1;
        hpmax = 60;
        atk = 10;
        def = 10;
        spd = 10;
        exp=0;
        hbb=0;
        Hbb=0;
    }else if(t == "Mons1"){
        lvl =1;
        exp = 0;
        hpmax = rand()%20+50;
        atk = rand()%5+10;
        def = rand()%3+5;
        spd = rand()%10+5;
        hbb=0;
        Hbb=0;
    }else if(t == "Mons2"){
        lvl =1;
        exp = 0;
        hpmax = rand()%20+50;
        atk = rand()%5+10;
        def = rand()%3+5;
        spd = rand()%10+5;
        hbb=0;
        Hbb=0;
    }else if(type == "Mons3"){
        lvl =1;
        exp = 0;
        hpmax = rand()%20+50;
        atk = rand()%5+10;
        def = rand()%3+5;
        spd = rand()%10+5;
        hbb=0;
        Hbb=0;
    }else if(type == "Mons4"){
        lvl =1;
        exp =0;
        hpmax = rand()%20+50;
        atk = rand()%5+10;
        def = rand()%3+5;
        spd = rand()%10+5;
        hbb=0;
        Hbb=0;
    }else if(type == "Mons5"){
        lvl =1;
        exp = 0;
        hpmax = rand()%20+50;
        atk = rand()%5+10;
        def = rand()%3+5;
        spd = rand()%10+5;
        hbb=0;
        Hbb=0;
    }
    hp = hpmax;    
    spd_t = spd;
    guard_on = false;
    dodge_on = false;
    equipment = NULL;
}

int Unit::lvlup(){
    while (exp>=10){
        exp = exp-10;
        lvl +=1;
    }
    upgrade();
    return lvl ;
}
void Unit::setlvl(int lvlnum){
    lvl = lvlnum;
}
void Unit::upgrade(){
    hpmax += 5*(lvl-1);
    atk += 5*(lvl-1);
    def += 2*(lvl-1);
    spd += 1*(lvl-1);
}
void Unit::downgrade(){
    hpmax -= 5*(lvl-1);
    atk -= 5*(lvl-1);
    def -= 2*(lvl-1);
    spd -= 1*(lvl-1);
}
void Unit::expp(int nump){
    exp = nump;
    
}

void Unit::newTurn(){
	guard_on = false; 
    dodge_on = false;
    spd_t = spd;
}
void Unit::endoturn(){
    if(hppart_head<=0){
        Hbk();
        Hbb++;
    }
    if((hppart_left_hand or hppart_right_hand)<=0){
        hbk();
        hbb++;
    }
}
void Unit::Hbk(){
    hp -=10;
}
void Unit::hbk(){
    atk -=5;
}
int Unit::beAttacked(int oppatk, string targetpart){
	int dmg =0;
	if(oppatk > def){
		dmg = oppatk-def;	
		if(guard_on) dmg = dmg/3;
	}	
	hp -= dmg;
    if(targetpart =="H"){
        hppart_head -= dmg;
    }if(targetpart =="LH"){
        hppart_left_hand -= dmg;
    }if(targetpart =="RH"){
        hppart_right_hand -= dmg;
    }if(targetpart =="LL"){
        hppart_left_leg -= dmg;
    }if(targetpart =="RL"){
        hppart_right_leg -= dmg;
    }
	if(hp <= 0){hp = 0;}
	
	return dmg;	
}

int Unit::attack(Unit &opp,string targetpart){
    
	return opp.beAttacked(atk,targetpart);
}

void Unit::showStatus(){
    if(type == "Maincha1"){
        cout << "\n--------------------------------------------------------\n"; 
        cout << name << "\n"; 
        cout << "HP: " << hp<<"/"<<hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def<< "\t\tSPD: "<< spd_t;        
        cout << "\n--------------------------------------------------------\n";
    }    
    else if(type == "Maincha2"){
        cout << "\n--------------------------------------------------------\n"; 
        cout << name << "\n"; 
        cout << "HP: " << hp<<"/"<<hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def<< "\t\tSPD: "<< spd_t;        
        cout << "\n--------------------------------------------------------\n";
    }    
    else if(type == "Mons1"){
        cout << "\t\t\t\t--------------------------------------------------------\n"; 
        cout << "\t\t\t\t" << name << "\n"; 
        cout << "\t\t\t\tHP: " << hp<<"/"<<hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def<< "\t\tSPD: "<< spd_t;
        cout << "\n\t\t\t\t--------------------------------------------------------\n";
    }
    else if(type == "Mons2"){
        cout << "\t\t\t\t--------------------------------------------------------\n"; 
        cout << "\t\t\t\t" << name << "\n"; 
        cout << "\t\t\t\tHP: " << hp<<"/"<<hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def<< "\t\tSPD: "<< spd_t;
        cout << "\n\t\t\t\t--------------------------------------------------------\n";
    }else if(type == "Mons3"){
        cout << "\t\t\t\t--------------------------------------------------------\n"; 
        cout << "\t\t\t\t" << name << "\n"; 
        cout << "\t\t\t\tHP: " << hp<<"/"<<hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def<< "\t\tSPD: "<< spd_t;
        cout << "\n\t\t\t\t--------------------------------------------------------\n";
    }else if(type == "Mons4"){
        cout << "\t\t\t\t--------------------------------------------------------\n"; 
        cout << "\t\t\t\t" << name << "\n"; 
        cout << "\t\t\t\tHP: " << hp<<"/"<<hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def<< "\t\tSPD: "<< spd_t;
        cout << "\n\t\t\t\t--------------------------------------------------------\n";
    }else if(type == "Mons5"){
        cout << "\t\t\t\t--------------------------------------------------------\n"; 
        cout << "\t\t\t\t" << name << "\n"; 
        cout << "\t\t\t\tHP: " << hp<<"/"<<hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def<< "\t\tSPD: "<< spd_t;
        cout << "\n\t\t\t\t--------------------------------------------------------\n";
    }
}

int Unit::heal(Unit &opp){
	return opp.beheal(atk);
}
int Unit::beheal(int oppatk){
    int h = rand()%21 + 10;
	if(hp + h > hpmax) hp = hpmax;
	else hp = hp + h;
	return h;
}
void Unit::guard(){
	guard_on = true;
}
void Unit::dodge(){
    dodge_on = true;
}

bool Unit::isDead(){
	if(hp <= 0) return true;
	else return false;
}

void Unit::equip(Equipment *newEquip){

    if(equipment != NULL){
        vector<int> oldStat = equipment->getStat();
        hpmax -= oldStat[0];
        atk -= oldStat[1];
        def -= oldStat[2];
        spd -= oldStat[3];
    }
    

    equipment = newEquip;
    vector<int> newStat = equipment->getStat();
    hpmax += newStat[0];
    atk += newStat[1];
    def += newStat[2];
    spd += newStat[3];


    if(hp > hpmax){
        hp = hpmax;
    }
    if(spd_t > spd){
        spd_t = spd;
    }
}
void Unit::set_death(){
    hp = 0;
}
string difRooM[6]={"first","second","third","fourth","last"};
string Room[6]={"1","2","3","4","5"};

void Unit::setloom(){
    hp=hpmax;
    if (hbb>=0)atk+=5*hbb;
    hbb =0;
    if (Hbb>=0)hp+=10*Hbb;
    Hbb =0;
}    




int main(){
    srand(time(0));
    
    string name;	
	cout << "Please input your name: ";
	getline(cin,name);	
	Unit hero1("Maincha1",name);
	Unit hero2("Maincha2","Kuutar");
    Unit Mons1("Mons1","slime");
    Unit Mons2("Mons2","pic");
    Unit Mons3("Mons3","pork");
    Unit Mons4("Mons4","Doctor");
    Unit Mons5("Mons5","cabbage");

    Equipment sword(0,8,4,0);
	Equipment axes(0, 16, 0,0);
    Equipment shield(0, 0, 8,0);
    Equipment armor(25, 0, 4,0);
    Equipment boots(0,0,3,9);      
    

    

    while (true){
        char PlorNt;
        int diffroom = 0;
        int clear1=0,clear2=0,clear3=0,clear4=0,clear5=0;
        cout << "Choose[C] or Exit[E] : ";
        cin >>PlorNt;
        if(PlorNt == 'E') break;
        else if (PlorNt == 'C') cout << "Please input difficulty first=1 second =2 third=3 fourth=4 last=5 :";
        else cout <<"you must play\n"<< "Please input difficulty first=1 second =2 third=3 fourth=4 last=5 :";
        
        cin >> diffroom;
       if (diffroom==1){
            Mons2.set_death();
            Mons3.set_death();
            Mons4.set_death();
            Mons5.set_death();
        } if(diffroom==2){
            Mons1.set_death();
            Mons3.set_death();
            Mons4.set_death();
            Mons5.set_death();
        } if(diffroom==3){
            Mons4.set_death();
            Mons5.set_death();
        } if(diffroom==4){
            Mons1.set_death();
            Mons3.set_death();
            Mons2.set_death();
            Mons5.set_death();
            Mons4.setlvl(5);
            Mons4.lvlup();
        } if(diffroom==5){
            Mons2.set_death();
            Mons3.set_death();
            Mons4.set_death();
            Mons1.set_death();
            Mons5.setlvl(10);
            Mons5.lvlup();
        }
        hero1.setloom();
        hero2.setloom();

        char eq;	
	cout << " [1] Sword \n [2] Axes \n [3] Shield \n [4] Armor \n [5] boots \n";
	cout << "Please selet your equipment for "<<name<<": ";
	cin >> eq;
    cin.ignore(1000, '\n');
	if(eq == '1') hero1.equip(&sword);
    else if(eq == '2') hero1.equip(&axes);
    else if(eq == '3') hero1.equip(&shield);
    else if(eq == '4') hero1.equip(&armor);
    else if(eq == '5') hero1.equip(&boots);
    cout << " [1] Sword \n [2] Axes \n [3] Shield \n [4] Armor \n [5] boots \n";
	cout << "Please selet your equipment for Kuutar: ";
	cin >> eq;
	if(eq == '1') hero2.equip(&sword);
    else if(eq == '2') hero2.equip(&axes);
    else if(eq == '3') hero2.equip(&shield);
    else if(eq == '4') hero2.equip(&armor);
    else if(eq == '5') hero2.equip(&boots);

        char player_action = '\0',player_target ='\0';
        string targetpart="";
        char monster1_action = '\0',monster2_action = '\0',monster3_action = '\0';
        player_action = '\0';
        int p = 0, m = 0, lvlh1=0, lvlh2=0;
        

        int turn_num = 1;
    while ((!hero1.isDead() or !hero2.isDead()) and (!Mons1.isDead()or!Mons2.isDead()or!Mons3.isDead()or!Mons4.isDead()or!Mons5.isDead())){
        
        
        if ((turn_num % (100-hero1.spd_t)) == 0){
            if (hero1.isDead()){
               //cout skip
            }else {
                hero1.newTurn();
                cout<<"\n  "<<name<<"turn";
                hero1.showStatus();
                cout <<"Action: attack[A] guard[G] dodge[D] heal[H]";
                cin >>player_action;
                if(player_action == 'G') hero1.guard();
                if(player_action == 'D') hero1.dodge();

                if(player_action == 'H') {
                    cout << "target :self[S] friend[F]";
                    cin >> player_target ;
                    cin.ignore(1000, '\n');
                    if (player_target == 'S')
                    p = hero1.heal(hero1);
                    if (player_target == 'F')
                    p = hero1.heal(hero2);
                }

                if(player_action == 'A') {
                    cout << "target : ";
                    if(!Mons1.isDead())cout <<"[1]";
                    if(!Mons2.isDead())cout <<"[2]"; 
                    if(!Mons3.isDead())cout <<"[3]";
                    if(!Mons4.isDead())cout <<"[4]";
                    if(!Mons5.isDead())cout <<"[5]";
                    cin>>player_target;
                    cin.ignore(1000, '\n');
                    cout <<"whichpart : head[H] righthand[RH] left[LH] left_leg[LL] rightleg[RL]";
                    getline(cin,targetpart);
                    if (player_target == '1')
                    
                    
                    p = hero1.attack(Mons1,targetpart);

                    if (player_target == '2')
                    p = hero1.attack(Mons2,targetpart);
                    if (player_target == '3')
                    p = hero1.attack(Mons3,targetpart);
                    if (player_target == '4')
                    p = hero1.attack(Mons4,targetpart);
                    if (player_target == '5')
                    p = hero1.attack(Mons5,targetpart);
                }
                cout <<p;
                hero1.endoturn();
            }
        }
        if ((turn_num % (100-hero2.spd_t)) == 0){
            if (hero2.isDead()){
               //cout skip
            }else {
                hero2.newTurn();
                cout<<"\n  "<<"Kuutar"<<"turn";
                hero2.showStatus();
                cout <<"Action: attack[A] guard[G] dodge[D] heal[H]";
                cin >>player_action;
                if(player_action == 'G') hero2.guard();
                if(player_action == 'D') hero2.dodge();

                if(player_action == 'H') {
                    cout << "target :self[S] friend[F]";
                    
                    cin >> player_target ;
                    cin.ignore(1000, '\n');
                    if (player_target == 'S')
                    p = hero2.heal(hero2);
                    if (player_target == 'F')
                    p = hero2.heal(hero1);
                }

                if(player_action == 'A') {
                    cout << "target :";
                    if(!Mons1.isDead())cout <<"[1]";
                    if(!Mons2.isDead())cout <<"[2]"; 
                    if(!Mons3.isDead())cout <<"[3]";
                    if(!Mons4.isDead())cout <<"[4]";
                    if(!Mons5.isDead())cout <<"[5]";
                    cin>>player_target;
                    cin.ignore(1000, '\n');
                    cout <<"whichpart : head[H] righthand[RH] left[LH] left_leg[LL] rightleg[RL]";

                    getline(cin,targetpart);
                    if (player_target == '1')
                    
                    
                    p = hero2.attack(Mons1,targetpart);

                    if (player_target == '2')
                    p = hero2.attack(Mons2,targetpart);
                    if (player_target == '3')
                    p = hero2.attack(Mons3,targetpart);
                    if (player_target == '4')
                    p = hero2.attack(Mons4,targetpart);
                    if (player_target == '5')
                    p = hero2.attack(Mons5,targetpart);
                }
                cout <<p;
                hero2.endoturn();
            }
        }
        if ((turn_num % (100-Mons1.spd_t)) == 0){
            if (Mons1.isDead()){

            }else {
                Mons1.newTurn();
                Mons1.showStatus();
            int tempp = rand()%3;
            int temp1 = rand()%2;
            int temp2 = rand()%5;

                if(tempp == 0) {Mons1.guard();cout <<"guard";}
                if(tempp == 1) {Mons1.dodge();
                cout <<"dodge";}
                if(tempp == 2) { 
                    if (temp2==0) targetpart ="H";
                    if (temp2==1) targetpart ="RH";
                    if (temp2==2) targetpart ="LH";
                    if (temp2==3) targetpart ="RL";
                    if (temp2==4) targetpart ="LL";
                    if (temp1 == 0){
                    
                    m = Mons1.attack(hero1,targetpart);
                    cout << "target : "<<name<<" ";
                    cout <<"whichpart : "<<targetpart<<" ";
                    }

                    if (temp1 == 1){
                    cout << "target :"<<"Kuutar"<<" ";
                    cout <<"whichpart : "<<targetpart<<" ";
                    m = Mons1.attack(hero2,targetpart);
                }
                cout <<m ;
                }
            Mons1.endoturn();    
            }
                

        }
        if ((turn_num % (100-Mons2.spd_t)) == 0){
            if (Mons2.isDead()){

            }else {
                Mons2.newTurn();
                Mons2.showStatus();
            int tempp = rand()%3;
            int temp1 = rand()%2;
            int temp2 = rand()%5;

                if(tempp == 0) {Mons2.guard();
                cout <<"guard";}
                if(tempp == 1) {Mons2.dodge();
                cout <<"dodge";}
                if(tempp == 2) { 
                    if (temp2==0) targetpart ="H";
                    if (temp2==1) targetpart ="RH";
                    if (temp2==2) targetpart ="LH";
                    if (temp2==3) targetpart ="RL";
                    if (temp2==4) targetpart ="LL";
                    if (temp1 == 0){
                    
                    m = Mons2.attack(hero1,targetpart);
                    cout << "target : "<<name<<" ";
                    cout <<"whichpart : "<<targetpart<<" ";
                    }

                    if (temp1 == 1){
                    cout << "target :"<<"Kuutar"<<" ";
                    cout <<"whichpart : "<<targetpart<<" ";
                    m = Mons2.attack(hero2,targetpart);
                }
                cout <<m ;
                }
            Mons2.endoturn();    
            }
        }
        if ((turn_num % (100-Mons3.spd_t)) == 0){
            if (Mons3.isDead()){

            }else 
            {
                Mons3.newTurn();
                Mons3.showStatus();
            int tempp = rand()%3;
            int temp1 = rand()%2;
            int temp2 = rand()%5;

                if(tempp == 0) {Mons3.guard();cout <<"guard";}
                if(tempp == 1) {Mons3.dodge();
                cout <<"dodge";}
                if(tempp == 2) { 
                    if (temp2==0) targetpart ="H ";
                    if (temp2==1) targetpart ="RH ";
                    if (temp2==2) targetpart ="LH ";
                    if (temp2==3) targetpart ="RL ";
                    if (temp2==4) targetpart ="LL ";
                    if (temp1 == 0){
                    
                    m = Mons3.attack(hero1,targetpart);
                    cout << "target : "<<name<<" ";
                    cout <<"whichpart : "<<targetpart<<" ";
                    }

                    if (temp1 == 1){
                    cout << "target :"<<"Kuutar"<<" ";
                    cout <<"whichpart : "<<targetpart<<" ";
                    m = Mons3.attack(hero2,targetpart);
                }
                cout <<m ;
                }
            Mons3.endoturn();    
            }
        }
        if ((turn_num % (100-Mons4.spd_t)) == 0){
            if (Mons4.isDead()){

            }else 
            {
                Mons4.newTurn();
                Mons4.showStatus();
            int tempp = rand()%3;
            int temp1 = rand()%2;
            int temp2 = rand()%5;

                if(tempp == 0) {Mons4.guard();
                cout <<"guard";}
                if(tempp == 1) {Mons4.dodge();
                cout <<"dodge";}
                if(tempp == 2) { 
                    if (temp2==0) targetpart ="H";
                    if (temp2==1) targetpart ="RH";
                    if (temp2==2) targetpart ="LH";
                    if (temp2==3) targetpart ="RL";
                    if (temp2==4) targetpart ="LL";
                    if (temp1 == 0){
                    
                    m = Mons4.attack(hero1,targetpart);
                    cout << "target : "<<name<<" ";
                    cout <<"whichpart : "<<targetpart<<" ";
                    }

                    if (temp1 == 1){
                    cout << "target :"<<"Kuutar"<<" ";
                    cout <<"whichpart : "<<targetpart<<" ";
                    m = Mons4.attack(hero2,targetpart);
                    }
                    cout <<m ;
                }
            Mons4.endoturn();    
            }
        }
        if ((turn_num % (100-Mons5.spd_t)) == 0){
            if (Mons5.isDead()){

            }else{
                Mons5.newTurn();
                Mons5.showStatus();
            int tempp = rand()%3;
            int temp1 = rand()%2;
            int temp2 = rand()%5;

                if(tempp == 0) {Mons5.guard();
                cout <<"guard";
                }
                if(tempp == 1) {Mons5.dodge();
                cout <<"dodge";}
                if(tempp == 2) { 
                    if (temp2==0) targetpart ="H";
                    if (temp2==1) targetpart ="RH";
                    if (temp2==2) targetpart ="LH";
                    if (temp2==3) targetpart ="RL";
                    if (temp2==4) targetpart ="LL";
                    if (temp1 == 0){
                    
                    m = Mons5.attack(hero1,targetpart);
                    cout << "target : "<<name<<" ";
                    cout <<"whichpart : "<<targetpart<<" ";
                    }

                    if (temp1 == 1){
                    cout << "target :"<<"Kuutar"<<" ";
                    cout <<"whichpart : "<<targetpart<<" ";
                    m = Mons5.attack(hero2,targetpart);
                }
                cout <<m ;
                }
            Mons5.endoturn();    
            }
        }
        turn_num++;
    }
    if(!hero1.isDead()or!hero2.isDead()){
    if (diffroom==1){
        hero1.expp(100);
        hero2.expp(100);
    }if (diffroom==2){
        hero1.expp(200);
        hero2.expp(200);
    }if (diffroom==3){
        hero1.expp(300);
        hero2.expp(300);
    }if (diffroom==4){
        hero1.expp(400);
        hero2.expp(400);
    }if (diffroom==5){
        hero1.expp(500);
        hero2.expp(500);
    }
    cout << "*******************************************************\n";
    for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
    cout << "*                   YOU WIN!!!                        *\n";
    for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
    cout << "*******************************************************\n";
    lvlh1 = hero1.lvlup();
    lvlh2 = hero2.lvlup();
    cout <<lvlh1;
    cout <<lvlh2;
}else {
    cout << "*******************************************************\n";
    cout << "*                                                     *\n";
    cout << "*                   YOU LOSE!!!                       *\n";
    cout << "*                                                     *\n";
    cout << "*******************************************************\n";

}


   

    }
    
}