#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct edge;
struct node {
    node() : num(-1), visited(false) {}

    int num;
    bool visited;       
    vector<edge> edges; 
};

struct edge {
    edge(bool cp, node *r) : panel(cp), locked(false), room(r) {}
    bool panel;   
    bool locked;  
    node *room;   
};

vector<node> house;

int panic_num;

void parse_input(void)
{
    vector<node *> intruders; 
    int room_num;
    house.clear();
    cin >> room_num >> panic_num;
        house.resize(room_num + 1);
    for(int room = 0; room < room_num; room++) {
        int door_num;
        house[room].num = room;
        string s;
        cin >> s;
        if(s == "I") 
            intruders.push_back(&house[room]);
        cin >> door_num;
        for(int door_idx = 0; door_idx < door_num; door_idx++) {
            int num;
            cin >> num;
            house[room].edges.push_back( edge(true, &house[num]) );
            house[num].edges.push_back( edge(false, &house[room]) );
        }
    }
    house[room_num].num = -1;
    for(int i = 0; i < intruders.size(); i++) {
        house[room_num].edges.push_back( edge(-1, intruders[i]) );
    }
}

int search(node *room)
{
    vector<edge>::iterator door;
    if(room->num == panic_num) return -1;
    room->visited = true;
    for(door = room->edges.begin(); door < room->edges.end(); ++door) {
        if(!door->room->visited && (door->panel || !door->locked)) {
            int rc = search(door->room);
            if(rc) {                 
                if(!door->panel) {
                    door->locked = true;
                    rc = 1;
                }
                return rc;
            }
        }
    }    
    return 0;
}

int maxflow(void)
{
    int rc, count = 0;
    node *master = &house[house.size() - 1];
    do {
        for(int i = 0; i < house.size(); i++) 
            house[i].visited = false;    
        rc = search(master);        
        if (rc == -1) count = -1; else  count += rc;
    } while(rc > 0);
    return count;
}


void process(void)
{
    int data_num, data_idx;
    cin >> data_num;
    for(data_idx = 0; data_idx < data_num; data_idx++) {
        parse_input();
        int cost = maxflow();
        if(cost == -1) cout << "PANIC ROOM BREACH" << endl;
        else cout << cost << endl;
    }
}    

int main(void)
{   
    process();
    return 0;
}
