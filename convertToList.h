File* convertToList(File *F){/*fonction qui reinserer les elements de la file F
    jusu'a l'arrivee au caractere ;*/
    File* P;//declarer une file P
    P=AllouerF(P);//allouer-le
    P=initialiser(P);//initiliser la file
    Element* temp=F->debut;//pointeur qui va parcourir la file F
    while(strcmp(temp->mot,";")!=0){
        P=enfiler(P,temp->mot);//enfiler le mot pointe par temp
        temp=temp->next;//parcourir temp vers l'adresse de l'element suivant
    }
    P=enfiler(P,temp->mot);//enfiler aussi ;
    return P;//retourner la file P
}
