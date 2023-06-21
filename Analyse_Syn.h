void Analyse_Syn(){
    File *F,*P;//declaration des files
    F=AllouerF();//allocation de file
    F=initialiser(F);//initialisation
    P=AllouerF();
    P=initialiser(P);
    FILE *F1,*F2,*F3;//declaration des trois fichiers
    char p[30];/*declaration d'une chaine de caracteres qui va lire
    chaque mot, separe par espace, des fichiers de mode lecture */
    F1=fopen("dictionnaire.txt","r");
    F2=fopen("programme.txt","r");
    F3=fopen("erreur lexical.txt","a");
    while(!feof(F2)){//inserer tout le fichier dans la file F
        fscanf(F2,"%s",p);//lire mot par mot de fichier qui le programme test
        F=enfiler(F,p);//insrer chaque mot lit par fscanf
    }
    while(F->debut){
       P=convertToList(F);//convetir chaque instruction se termine par ; au liste
       //suite d'analyses syntaxiques suivant le debut d'instruction
       if(strcmp(P->debut->mot,"variable")==0){
            /*si linstruction commence par
            variable, on fait l'appel a la fonction Analyse_Syn_Var */
            Analyse_Syn_Var(P);
            affiche(P);
            while(P->debut) defiler(P);
       }
       else if(strcmp(P->debut->mot,"debut")==0){
            Analyse_Syn_Deb(P);
            affiche(P);
            while(P->debut) defiler(P);
       }
       else if(strcmp(P->debut->mot,"ecrire")==0){
                Analyse_Syn_Ecrire(P);
                while(P->debut) defiler(P);
            }
        else if(strcmp(P->debut->mot,"lire")==0){
                Analyse_Syn_Lire(P);
                while(P->debut) defiler(P);
            }
        else if(strcmp(P->debut->mot,"si")==0){
                Analyse_Syn_Si(P);
                while(P->debut) defiler(P);
            }
            /*apres le traitement de chaque instruction on fait vider
            la file P pour le remplir par l'instruction suivante
            et le meme traitement jusqu'on obtient une file F vide */
       else if(strcmp(P->debut->mot,"sinon")==0){
                Analyse_Syn_Sinon(P);
                while(P->debut) defiler(P);
            }
        else if(strcmp(P->debut->mot,"fin")==0){
                Analyse_Syn_fin(P);
                while(P->debut) defiler(P);
            }
        else{
            /*si l'instruction ne commence par aucun mot parmi les mots indiques
            dans les instructions de conditions precedentes il affiche
            le message suivant dans le fichier erreur */
            fputs("\nerreur de syntaxe : il faut respecter l'algorithme",F3);
        }
       while(strcmp(F->debut->mot,";")!=0){
           F=defiler(F);
       }
       F=defiler(F);
    }
    fclose(F1);
    fclose(F2);
    fclose(F3);
}
