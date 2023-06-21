void Analyse_lix(){
    File *F,*P;//declarer deux files
    F=AllouerF();//allocation de la 1ere file
    F=initialiser(F);//son initialisation
    P=AllouerF();//allocation de la 2eme file
    P=initialiser(P);//son initialisation
    FILE *F1,*F2,*F3;//declarer 3 fichiers
    char p[13];
    F1=fopen("dictionnaire.txt","r");/*F1 dictionnaire de differents
    Les entrées-sorties conversationnelles*/
    F2=fopen("Programme.txt","r");//F2 contient le programme test de l'utilisateur
    F3=fopen("erreur lexical.txt","w");//F3 identifier les erreurs de fichier programme
    while(!feof(F2)){//inserer le contenu de fichier programme
        fscanf(F2,"%s",p);
        F=enfiler(F,p);
    }
    while(!feof(F1)){//inserer le contenu de fichier dictionnaire
        fscanf(F1,"%s",p);
        P=enfiler(P,p);
    }
    Element* temp=F->debut;//on declare un pointeur de type element pour parcourir la file F
    while(temp){
        if(comparFile(P,temp->mot)!=1){
            //chaque mot n'existe pas dans le dictionaire,il va le declarer dans F3
            fprintf(F3,"ATTENTION !!! le mot '%s' n'existe pas dans le dictionaire\n",temp->mot);
        }
        temp=temp->next;
    }
    fclose(F1);
    fclose(F2);
    fclose(F3);
}
