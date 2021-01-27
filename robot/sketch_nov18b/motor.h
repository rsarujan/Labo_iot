

class motor {
	int ena;
	int enb;
	int in4;
	int in3;
	int in2;
	int in1;
public:
  int vitesse = 200;
	motor(int ena, int enb, int in4, int in3, int in2, int in1);
	~motor();

	void avancer();
	void reculer();
	void droite();
	void gauche();
  void arret();
};
