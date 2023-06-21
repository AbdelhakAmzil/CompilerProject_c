typedef struct node{
    char* mot;//chaque element de la liste contient une chaine de caractere
    struct node* next;//champ de l'adresse suivante
}Element;

Element* AllouerNoued(){
    Element* L;//declarer une liste
    L=(Element*)malloc(sizeof(Element));//allouer la liste
    L->next=NULL;//pointer l'adresse suivante de la liste vers null
    return L;//retourner La liste
}

typedef struct {//declarater la file
    Element* debut;//le debut pointe sur le 1er element de la liste
    Element* fin;//la fin pointe sur le dernier element de la liste
    int taille;
}File;

File* AllouerF(){//allocation de la file
    File* AF;
    AF=(File*)malloc(sizeof(File));
    AF->debut=NULL;
    AF->fin=NULL;
    AF->taille=0;
    return AF;
}

File* initialiser(File* F){
    F->debut=NULL;
    F->fin=NULL;
    F->taille=0;
    return F;
}

File* enfiler(File* F,char* donnee){
    Element* N;
    N=AllouerNoued();
    N->mot=(char*)malloc(sizeof(strlen(donnee)+1));
    strcpy(N->mot,donnee);
    if(F->fin==NULL){
        F->debut=N;
        F->fin=N;
    }
    else{
        F->fin->next=N;
        F->fin=N;
    }
    F->taille++;
    return F;
}

File* defiler(File *F){
    if(F->debut==NULL) return F;
    else{
        Element* Supp;
        Supp=F->debut;
        if(F->taille==1){
            F->debut=NULL;
            F->fin=NULL;
        }
        else F->debut=F->debut->next;
        free(Supp);
        F->taille--;
        return F;
    }
}


void affiche(File *F){
    Element *courant;
    courant=F->debut;
    while(courant){
        printf("=> %s\n",courant->mot);
        courant=courant->next;
    }
}
