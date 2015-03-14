#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "binarytree.h"
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Huffman : public BinaryTree<char>{
public:
    Huffman();

    string decode(string) const;

    string encode(string) const;

    void insert(char);

    void remove(char);

    bool contains(char) const;
private:

    void insert(char, string);

    Node<char> *remove(Node<char> *, char);

    map<char, string> encoding;
};
Huffman::Huffman() : BinaryTree<char>(){
    root = new Node<char>('*');
    encoding.insert( std::pair<char,string>('a',"1110") );
    encoding.insert( std::pair<char,string>('b',"110000") );
    encoding.insert( std::pair<char,string>('c',"01001") );
    encoding.insert( std::pair<char,string>('d',"11111") );
    encoding.insert( std::pair<char,string>('e',"100") );
    encoding.insert( std::pair<char,string>('f',"00101") );
    encoding.insert( std::pair<char,string>('g',"110011") );
    encoding.insert( std::pair<char,string>('h',"0110") );
    encoding.insert( std::pair<char,string>('i',"1011") );
    encoding.insert( std::pair<char,string>('j',"001001011") );
    encoding.insert( std::pair<char,string>('k',"0010011") );
    encoding.insert( std::pair<char,string>('l',"11110") );
    encoding.insert( std::pair<char,string>('m',"00111") );
    encoding.insert( std::pair<char,string>('n',"1010") );
    encoding.insert( std::pair<char,string>('o',"1101") );
    encoding.insert( std::pair<char,string>('p',"110001") );
    encoding.insert( std::pair<char,string>('q',"001001001") );
    encoding.insert( std::pair<char,string>('r',"0101") );
    encoding.insert( std::pair<char,string>('s',"0111") );
    encoding.insert( std::pair<char,string>('t',"000") );
    encoding.insert( std::pair<char,string>('u',"01000") );
    encoding.insert( std::pair<char,string>('v',"001000") );
    encoding.insert( std::pair<char,string>('w',"00110") );
    encoding.insert( std::pair<char,string>('x',"001001010") );
    encoding.insert( std::pair<char,string>('y',"110010") );
    encoding.insert( std::pair<char,string>('z',"001001000") );

    for(char index = 'a'; index <= 'z'; ++index)
        insert(index);

}

string Huffman::encode(string message) const{
    string toRet;
    transform(message.begin(), message.end(), message.begin(), ::tolower);
    for(char letter: message){
        if(encoding.find(letter) == encoding.end()){
            toRet += "1010010001111011110";
            continue;
        }
        toRet += encoding.find(letter)->second;
    }
    return toRet;
}

string Huffman::decode(string message) const {
    Node<char> * workingNode = root;
    string toRet;

    for(char dir: message){
        if(dir == '0'){
            if(workingNode->lChild == nullptr){
                toRet += ' ';
                workingNode = root;
            }
            else
                workingNode = workingNode->lChild;
        }
        else{
            if(workingNode->rChild == nullptr){
                toRet += ' ';
                workingNode = root;
            }
            else
                workingNode = workingNode->rChild;
        }

        if(workingNode->data != '*'){
            toRet += workingNode->data;
            workingNode = root;
        }
    }
    return toRet;
}

void Huffman::insert(char data, string path){
    Node<char> * workingNode = root;

    for(char dir: path){
        if(dir == '0'){
            if(workingNode->lChild == nullptr)
                workingNode->lChild = new Node<char>('*');
            workingNode = workingNode->lChild;
        }
        else{
            if(workingNode->rChild == nullptr)
                workingNode->rChild = new Node<char>('*');
            workingNode = workingNode->rChild;
        }
    }

    workingNode->data = data;
}

void Huffman::insert(char data) {
    if(encoding.find(data) == encoding.end())
        return;
    insert(data, encoding.find(data)->second);
}

void Huffman::remove(char data) {
    //Don't remove nodes;
    ;
}

bool Huffman::contains(char data) const {
    return (encoding.find(data) == encoding.end());
}

#endif