// [TIMXAD] ~ [4.1_v2] @ [Oct 3, 2013]
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cassert>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define DOW(i, A, a) for (int i = (A), _a = (a); i >= _a; --i)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define FIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

#define dbg(x) cout << #x << " = " << x << endl
#define ok() cout << "@OK!" << endl
#define pb push_back
#define mp make_pair
#define sz(a) (int) a.size()
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define MAX_POINT 2000
#define NORMAL_POINT 1000

struct Ability {
	string text;
	int cost;
	int type; // 0 : pre, 1 : post, 2 : destroyed

	Ability() { cost = 0, type = -1, text = ""; }
	Ability(string _text, int _cost, int _type) {
		text = _text, cost = _cost, type = _type;
	}

	void show() {
		printf("Abi = %-10s, cost = %3d, type = %s\n", text.c_str(), cost, type == 0 ? "pre" : type == 1 ? "post" : "dest");
	}
};

map<string, Ability> m;
const string
		ATTACK = "attack",
		HEALTH = "health",
		ABILITIES = "abilities",
		POISON = "poison",
		POISON_ALL = "poison_all",
		POWERUP = "powerup",
		HEAL = "heal",
		BACKFIRE = "backfire",
		CROUCH = "crouch",
		WARSONG = "warsong",
		FORTITUDE = "fortitude",
		SACRIFICE = "sacrifice";

void init() {
	Ability all[] = {
			Ability(POISON, 10, 0),
			Ability(POISON_ALL, 15, 0),
			Ability(POWERUP, 10, 0),
			Ability(HEAL, 2, 0),
			Ability(BACKFIRE, -2, 0),
			Ability(CROUCH, -1, 1),
			Ability(WARSONG, 5, 2),
			Ability(FORTITUDE, 1, 2),
			Ability(SACRIFICE, -1, 2) };

//	cout << "Init \n";
	for (int i = 0; i < sizeof(all) / sizeof(all[0]); ++i) {
		m[all[i].text] = all[i];
//		all[i].show();
	}
//	cout << "  *** * ** ** * * " <<  endl;
}

inline string toString(int x) {
	stringstream ss;
	string result;
	ss << x;
	ss >> result;
	return result;
}

struct Magic {
	string ability;
	int total;

	Magic() {
		total = 0;
	}

	Magic(string _a, int _t) {
		ability = _a, total = _t;
	}

	int getCost() {
		return m[ability].cost * total;
	}

	bool isValid() {
		return m.count(ability) && total >= 0 && (total % 100 == 0) && (total <= 1000);
	}

	void show() {
		printf("\tMagic : %s, total = %d, cost = %d\n", m[ability].text.c_str(), total, m[ability].cost * total);
	}
};

struct Card {
	int att, hp;
	vector<Magic> magic;

	Card() {
		att = hp = 0;
	}

	Card(int _att, int _health) {
		att = _att, hp = _health;
	}

	void addAbility(string ability, int total) {
		magic.push_back(Magic(ability, total));
	}

	bool isValid() {
		if (att < 0 || hp < 0 || att % 100 || hp % 100 || magic.size() > 2) return false;
		REP(i, magic.size()) if (!magic[i].isValid()) return false;

		int cost = 0;
		cost = min(NORMAL_POINT, att);
		if (att > NORMAL_POINT) cost += (att - NORMAL_POINT) * 5;
		cost += min(NORMAL_POINT, hp);
		if (hp > NORMAL_POINT) cost += (hp - NORMAL_POINT) * 5;

		REP(i, magic.size()) {
			cost += magic[i].getCost();
			if (m[magic[i].ability].text == CROUCH && magic[i].total > att) return false;
		}
//		if (cost < MAX_POINT) {
//			cout << "Not optimized! ";
//			show();
//		}

		return cost <= MAX_POINT;
	}

	void show() {
		printf("att = %d, hp = %d, abi = %d\n", att, hp, magic.size());
		FIT(it, magic) it->show();
	}

	string toJSON() {
		string x = "{\"" + ATTACK + "\": " + toString(att) + ",";
		x = x + "\"" + HEALTH + "\": " + toString(hp) + ",";
		x = x + "\"" + ABILITIES + "\": {";
		bool first = true;
		FIT(it, magic) {
			if (first) first = false;
			else x = x + ",";
			x = x + "\"" + it->ability + "\": " + toString(it->total);
		}
		x = x + "}}";
		return x;
	}
};

class Parser {
	string json;
	int pos, len;

	string readUntil(string termination) {
		string rs = "";
		while (pos < len && termination.find(json[pos]) == string::npos) {
			rs.push_back(json[pos++]);
		}
		return rs;
	}

	int toInt(string x) {
		int rs;
		stringstream ss;
		ss << x;
		ss >> rs;
		return rs;
	}

	string getText(string x) {
		return x.substr(1, x.length() - 2);
	}

	bool hasNext() {
		return ++pos < len - 1;
	}

	pair<string, string> getPair() {
		string key = getText(readUntil(":"));
		pos++;
		string value;
		if (key == ABILITIES) {
			pos++;
			value = readUntil("}");
		} else {
			value = readUntil(",");
		}
//		cout << key << " -> " << value << endl;
		++pos;
		return make_pair(key, value);
	}

	pair<string, int> getPair(string text) {
//		dbg(text);
		int pos = text.find(':');
		string key = getText(text.substr(0, pos));
		string valueStr = text.substr(pos + 1, text.length() - pos - 1);
		int value = toInt(valueStr);
//		cout << valueStr << endl;
//		cout << key << " !> " << value << endl;
		return make_pair(key, value);
	}

	Card nextCard() {
//		cout << pos << " " << json[pos] << endl;
		Card card;
		//assert(json[pos] == '{');
		++pos;
		REP(i, 3) {
			pair<string, string> info = getPair();
			if (info.first != ABILITIES) {
				if (info.first == HEALTH) {
					card.hp = toInt(info.second);
				} else if (info.first == ATTACK) {
					card.att = toInt(info.second);
				} else {
					//assert(false);
				}
			} else {
				vector<Magic> magic;
				string details = info.second;
				if (details == "") continue;
				int pos = details.find(',');
				pair<string, int> p;
				if (pos == string::npos) {
					p = getPair(details);
					magic.push_back(Magic(p.first, p.second));
				} else {
					p = getPair(details.substr(0, pos));
					magic.push_back(Magic(p.first, p.second));
					p = getPair(details.substr(pos + 1, details.length() - pos - 1));
					magic.push_back(Magic(p.first, p.second));
				}
				card.magic = magic;
			}
		}
		return card;
	}

public:
	vector<Card> parse(string _json) {
		vector<Card> cards;
		json = "";
		REP(i, _json.length()) {
			if (_json[i] != ' ' && _json[i] != '\n' && _json[i] != '\t') {
				json.push_back(_json[i]);
			}
		}
//		dbg(json);
		len = json.length();
		pos = 0;

		//assert(json[0] == '[');
		//assert(json[len - 1] == ']');

		while (hasNext()) {
			cards.push_back(nextCard());
			pos++;
		}
		return cards;
	}
};

struct Deck {
	Card cards[3][3];

	Deck() {}

	Deck(string json) {
		Parser p;
		vector<Card> c = p.parse(json);
		FIT(it, c) {
			assert(it->isValid());
		}
		int pos = 0;
		REP(i, 3) REP(j, 3) cards[i][j] = c[pos++];
	}

	void show() {
		REP(i, 3) REP(j, 3) {
			cout << "CARD  " << i << " " << j << endl;
			cards[i][j].show();
		}
	}

	string toJSON() {
		string json = "[";
		bool isFirst = true;
		REP(i, 3) REP(j, 3) {
			Card cur = cards[i][j];
			if (isFirst) isFirst = false;
			else json.push_back(',');
			json += cur.toJSON();
		}
		json.push_back(']');
		return json;
	}
};

struct BattleResult {
	int winner, numRound, hp1, hp2;

	BattleResult() {}

	BattleResult(int _win, int _round, int h1, int h2) {
		winner = _win, numRound = _round, hp1 = h1, hp2 = h2;
	}

	void show() {
		cout << " **** BATTLE RESULT **** " << endl;
		cout << "Winner is " << (winner ? "second" : "first") << endl;
		printf("Round = %d, hp1 = %d, hp2 = %d\n", numRound, hp1, hp2);
	}
};

class Arena {
	Card c[2][3][4];
	int front[2][3], hp[2];
	int warSong[2];

	void destroyed(int player, int row, int col) {
		FIT(it, c[player][row][col].magic) {
			if (it->ability == WARSONG) {
				warSong[player] += it->total;
				continue;
			}

			if (it->ability == FORTITUDE) {
				hp[player] += it->total;
				continue;
			}

			if (it->ability == SACRIFICE) {
				hp[player] -= it->total;
				continue;
			}
		}
	}
public:
	BattleResult match(const Deck& first, const Deck& second) {
		REP(i, 3) REP(j, 3) c[0][i][j] = first.cards[i][j];
		REP(i, 3) REP(j, 3) c[1][i][j] = second.cards[i][j];

		hp[0] = hp[1] = 0;
		warSong[0] = warSong[1] = 0;
		REP(t, 2) REP(i, 3) REP(j, 3) hp[t] += c[t][i][j].hp;

		REP(t, 2) REP(i, 3) front[t][i] = 0;
		for (int i = 1; i <= 10; ++i) {
			// last is destroyed -> warsong
			REP(t, 2) {
				if (warSong[t] > 0) {
					REP(k, 3) {
						int r = front[t][k];
						if (r > 2) continue;
						c[t][r][k].att += warSong[t];
					}
				}
			}

//			REP(t, 2) {
//				if (warSong[t] > 0) {
//					cout << "warsong for " << t << " " << warSong[t] << endl;
//					REP(k, 3) {
//						int r = front[t][k];
//						if (r > 2) continue;
//						cout << c[t][r][k].att << endl;
//					}
//				}
//			}
			// pre-attack
			REP(t, 2) {
				REP(k, 3) {
					int r = front[t][k];
					if (r > 2) continue;

					FIT(it, c[t][r][k].magic) {
						if (m[it->ability].type == 0) { // pre-attack magic
							string abi = it->ability;

							if (abi == POISON) {
								int rOposite = front[1 - t][k];
								if (rOposite > 2) continue;
								c[1 - t][rOposite][k].att -=  it->total;
								continue;
							}

							if (abi == POISON_ALL) {
								REP(l, 3) {
									int rOposite = front[1 - t][l];
									if (rOposite > 2) continue;
									c[1 - t][rOposite][l].att -= it->total;
								}
								continue;
							}

							if (abi == POWERUP) {
								c[t][r][k].att += it->total;
								continue;
							}

							if (abi == HEAL) {
								hp[t] += it->total;
								continue;
							}

							if (abi == BACKFIRE) {
								hp[t] -= it->total;
								continue;
							}
						}
					}
				}
			}

			// After pre-attack
			if (hp[0] <= 0) return BattleResult(1, i, hp[0], hp[1]);
			if (hp[1] <= 0) return BattleResult(0, i, hp[0], hp[1]);

			warSong[0] = warSong[1] = 0;

			// Fight
			REP(t, 3) {
				int first = front[0][t], second = front[1][t];
				int attF = (first > 2 ? 0 : c[0][first][t].att);
				int attS = (second > 2 ? 0 : c[1][second][t].att);

				if (attF < attS) {
					hp[0] -= attS - attF;
					// destroyed first
					if (first <= 2) {
						destroyed(0, first, t);
						front[0][t]++;
					}
					// post-attack -> second
					if (second <= 2) {
						FIT(it, c[1][second][t].magic) {
							if (it->ability == CROUCH) {
								c[1][second][t].att -= it->total;
							}
						}
					}

				} else if (attF > attS) {
					hp[1] -= attF - attS;
					// destroyed second;
					if (second <= 2) {
						destroyed(1, second, t);
						front[1][t]++;
					}

					// post-attack -> first
					if (first <= 2) {
						FIT(it, c[0][first][t].magic) {
							if (it->ability == CROUCH) {
								c[0][first][t].att -= it->total;
							}
						}
					}
				} else {
					// destroyed both
					if (first <= 2) {
						destroyed(0, first, t);
						front[0][t]++;
					}
					if (second <= 2) {
						destroyed(1, second, t);
						front[1][t]++;
					}
				}
			}

//			cout << "After round " << i << " " << hp[0] << " " << hp[1] << endl;
			// After
			if (hp[0] <= 0) return BattleResult(1, i, hp[0], hp[1]);
			if (hp[1] <= 0) return BattleResult(0, i, hp[0], hp[1]);
		}
		int win = hp[0] <= hp[1] ? 1 : 0;
		return BattleResult(win, 11, hp[0], hp[1]);
	}
};

class Killer {
	vector<vector<Card> > cards;

	Deck cur, enemy;
	Arena arena;
	bool found;

	void go(int step) {
		if (found) return;
		if (step > 2) {
			if (arena.match(cur, enemy).winner == 0) found = true;
			return;
		}

		REP(i, cards.size()) {
			REP(j, 3) {
				cur.cards[j][step] = cards[i][j];
				go(step + 1);
			}
		}
	}

public:
	Killer() {
		string sample[] = {
				"[{\"attack\": 1000,\"health\": 1000,\"abilities\": {}},{\"attack\": 1000,\"health\": 1000,\"abilities\": {}},{\"attack\": 1000,\"health\": 1000,\"abilities\": {}}]",
				"[{\"attack\": 1100,\"health\": 500,\"abilities\": {}},{\"attack\": 1100,\"health\": 500,\"abilities\": {}},{\"attack\": 1100,\"health\": 500,\"abilities\": {}}]",
				"[{\"attack\": 1100,\"health\": 500,\"abilities\": {}},{\"attack\": 1000,\"health\": 1000,\"abilities\": {}},{\"attack\": 1100,\"health\": 500,\"abilities\": {}}]",
				"[{\"attack\": 1000,\"health\": 0,\"abilities\": {\"crouch\": 1000,\"warsong\": 400}},{\"attack\": 1100,\"health\": 500,\"abilities\": {\"powerup\": 100,\"sacrifice\": 1000}},{\"attack\": 0,\"health\": 1400,\"abilities\": {\"sacrifice\": 1000}}]",
				"[{\"attack\": 400,\"health\": 600,\"abilities\": {\"warsong\": 200}},{\"attack\": 1200,\"health\": 0,\"abilities\": {}},{\"attack\": 1000,\"health\": 1000,\"abilities\": {}}]",
				"[{\"attack\": 400,\"health\": 600,\"abilities\": {\"warsong\": 200}},{\"attack\": 1000,\"health\": 500,\"abilities\": {\"warsong\": 100}},{\"attack\": 1200,\"health\": 0,\"abilities\": {}}]",
				"[{\"attack\": 800,\"health\": 1000,\"abilities\": {\"heal\": 100}},{\"attack\": 1000,\"health\": 1000,\"abilities\": {\"crouch\": 1000,\"fortitude\": 1000}},{\"attack\": 1100,\"health\": 500,\"abilities\": {}}]",
				"[{\"attack\": 1000,\"health\": 1000,\"abilities\": {\"crouch\": 1000,\"fortitude\": 1000}},{\"attack\": 800,\"health\": 1000,\"abilities\": {\"heal\": 100}},{\"attack\": 1100,\"health\": 500,\"abilities\": {}}]",
				"[{\"attack\": 1100,\"health\": 500,\"abilities\": {}},{\"attack\": 600,\"health\": 400,\"abilities\": {\"poison\": 100}},{\"attack\": 1000,\"health\": 1000,\"abilities\": {}}]",
				"[{\"attack\": 1000,\"health\": 1000,\"abilities\": {}},{\"attack\": 1000,\"health\": 500,\"abilities\": {\"poison_all\": 100,\"crouch\": 1000}},{\"attack\": 1000,\"health\": 1000,\"abilities\": {}}]",
				"[{\"attack\": 1000,\"health\": 500,\"abilities\": {\"poison_all\": 100,\"crouch\": 1000}},{\"attack\": 1000,\"health\": 1000,\"abilities\": {}},{\"attack\": 1000,\"health\": 1000,\"abilities\": {}}]"};

		found = false;
		Parser bot;
		REP(i, sizeof(sample) / sizeof(sample[0])) {
			vector<Card> card = bot.parse(sample[i]);
			//FIT(it, card) assert(it->isValid());
			cards.push_back(card);
		}
	}

	Deck findKillingDeck(Deck _enemy) {
		enemy = _enemy;
		go(0);
		if (found) return cur;
		assert(false);
		return _enemy; // accept to lose :'(
	}
};

Card getCardFromLine(string line) {
	stringstream ss;
	ss << line;
	Card card;
	ss >> card.att;
	ss >> card.hp;
	int totalMagic, total;
	string ability;
	ss >> totalMagic;
	REP(i, totalMagic) {
		ss >> ability >> total;
		card.magic.push_back(Magic(ability, total));
	}
	return card;
}

void genCard() {
	freopen("./IO/card", "r", stdin);
	freopen("./IO/card_json", "w", stdout);

	string s;
	vector<Card> cards;
	while (getline(cin, s)) {
		if (s == "" || s[0] == '/') continue;
		Card card = getCardFromLine(s);
		//assert(card.isValid());
		cards.push_back(card);
		if (cards.size() == 3) {
			cout << "[";
			bool first = true;
			FIT(it, cards) {
				if (first) first = false;
				else cout << ",";
				cout << it->toJSON();
			}
			cout << "]" << endl;
			cards.clear();
		}
	}
}

string myDeck = "[	 	{ \"attack\": 0, 	\"health\" : 0, 	\"abilities\": {\"warsong\": 400} 	}, 	 	{ \"attack\": 0, 	\"health\" : 0, 	\"abilities\": {\"warsong\": 400} 	}, 	 	{ \"attack\": 0, 	\"health\" : 0, 	\"abilities\": {\"warsong\": 400} 	}, 	 	{ \"attack\": 1100, 	\"health\": 500, 	\"abilities\": {\"powerup\": 100, \"sacrifice\": 1000} 	}, 	 	{ \"attack\": 1100, 	\"health\": 500, 	\"abilities\": {\"powerup\": 100, \"sacrifice\": 1000} 	}, 	 	{ \"attack\": 1100, 	\"health\": 500, 	\"abilities\": {\"powerup\": 100, \"sacrifice\": 1000} 	}, 	 	{ \"attack\": 0, 	\"health\": 1400	, 	\"abilities\": {\"sacrifice\": 1000} 	}, 	 	{ \"attack\": 0, 	\"health\": 1400	, 	\"abilities\": {\"sacrifice\": 1000} 	}, 	 	{ \"attack\": 0, 	\"health\": 1400	, 	\"abilities\": {\"sacrifice\": 1000} 	} ]";
int main() {
#ifdef LOCAL
	freopen("./IO/deck", "r", stdin);
#endif
	init();
//	genCard();
	string json, token;
	while (cin >> token) json = json.append(token);

	Killer k;
	Deck enemy = Deck(json);
	Deck myDeck = k.findKillingDeck(enemy);
	cout << myDeck.toJSON() << endl;
}
