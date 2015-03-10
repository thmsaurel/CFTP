/*******************************************************************************
 *
 * File Name         : list.h
 * Created By        : Thomas Aurel
 * Creation Date     : January 27th, 2015
 * Last Change       : January 27th, 2015 at 16:40:16
 * Last Changed By   : Thomas Aurel
 * Purpose           :
 *
 *******************************************************************************/
struct node{
    char *word;
    list *next;
};

list createList(char *word);
list addElem(char *word, list list_a);
list addElemFirst(char *word, list list_a);
list addElemPos(char *word, list list_a, int pos);
list getElem(int pos, list list_a);
list lastElem(list list_a);

