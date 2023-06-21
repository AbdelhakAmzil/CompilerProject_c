void Analyse_Syn_fin(File *F){
    FILE *F2,*F3;
    F2=fopen("programme.txt","r");
    F3=fopen("erreur lexical.txt","a");
    F=defiler(F);
    if(strcmp(F->debut->mot,";")==0){
        F=defiler(F);
    else if(F->debut!=NULL) fputs("\nerreur de syntaxe : rien s'ecrire apres 'Fin'",F3);
    fclose(F2);
    fclose(F3);
}
