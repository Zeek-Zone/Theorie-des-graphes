


// une structure representant l'arc
typedef struct arc{   // arete
	int src,
        dest,
        poids;
}Arc;


// la structure representant le graphe par ses arcs (aretes)
typedef struct graphe{

	int numSommet, numLien;
	Arc* arcs;

}Graphe;

Graphe* creerGraphe(int numSommet, int numLien);



