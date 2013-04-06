#ifndef GENEBOT_H_
#define GENEBOT_H_

class GeneBot {
public:
	GeneBot();
	virtual ~GeneBot();

	//breeding

	//position handling

	//gets & sets
protected:
	int attack, defence;
	int speed, range;
	int evasion, health;
	float shape, size, color;
};

#endif
