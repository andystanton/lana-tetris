
#include "Alphabet.h"

Alphabet* Alphabet::alphabet = nullptr;

Alphabet* Alphabet::getInstance() {
    if (alphabet == nullptr) {
        alphabet = new Alphabet();
    }
    return alphabet;
}

Character* Alphabet::getChar(int character) {
    return alphabetMap[character];
}

bool** Alphabet::initaliseArray() {
    bool** newArray = new bool*[5];
    for (int i=0; i<5; i++) {
        newArray[i] = new bool[7];
        for (int j = 0; j<7; j++) {
            newArray[i][j] = false;
        }
    }
    return newArray;
}

void Alphabet::addToAlphabet(int ascii, Character* character) {
    pair<int, Character*> pair(ascii, character);
    alphabetMap.insert(pair);
}

Alphabet::Alphabet() {
    bool** charArray0 = initaliseArray();
    addToAlphabet(0, new Character(charArray0));
    
    bool** charArray1 = initaliseArray();
    addToAlphabet(1, new Character(charArray1));
    
    bool** charArray2 = initaliseArray();
    addToAlphabet(2, new Character(charArray2));
    
    bool** charArray3 = initaliseArray();
    addToAlphabet(3, new Character(charArray3));
    
    bool** charArray4 = initaliseArray();
    addToAlphabet(4, new Character(charArray4));
    
    bool** charArray5 = initaliseArray();
    addToAlphabet(5, new Character(charArray5));
    
    bool** charArray6 = initaliseArray();
    addToAlphabet(6, new Character(charArray6));
    
    bool** charArray7 = initaliseArray();
    addToAlphabet(7, new Character(charArray7));
    
    bool** charArray8 = initaliseArray();
    addToAlphabet(8, new Character(charArray8));
    
    bool** charArray9 = initaliseArray();
    addToAlphabet(9, new Character(charArray9));
    
    bool** charArray10 = initaliseArray();
    addToAlphabet(10, new Character(charArray10));
    
    bool** charArray11 = initaliseArray();
    addToAlphabet(11, new Character(charArray11));
    
    bool** charArray12 = initaliseArray();
    addToAlphabet(12, new Character(charArray12));
    
    bool** charArray13 = initaliseArray();
    addToAlphabet(13, new Character(charArray13));
    
    bool** charArray14 = initaliseArray();
    addToAlphabet(14, new Character(charArray14));
    
    bool** charArray15 = initaliseArray();
    addToAlphabet(15, new Character(charArray15));
    
    bool** charArray16 = initaliseArray();
    addToAlphabet(16, new Character(charArray16));
    
    bool** charArray17 = initaliseArray();
    addToAlphabet(17, new Character(charArray17));
    
    bool** charArray18 = initaliseArray();
    addToAlphabet(18, new Character(charArray18));
    
    bool** charArray19 = initaliseArray();
    addToAlphabet(19, new Character(charArray19));
    
    bool** charArray20 = initaliseArray();
    addToAlphabet(20, new Character(charArray20));
    
    bool** charArray21 = initaliseArray();
    addToAlphabet(21, new Character(charArray21));
    
    bool** charArray22 = initaliseArray();
    addToAlphabet(22, new Character(charArray22));
    
    bool** charArray23 = initaliseArray();
    addToAlphabet(23, new Character(charArray23));
    
    bool** charArray24 = initaliseArray();
    addToAlphabet(24, new Character(charArray24));
    
    bool** charArray25 = initaliseArray();
    addToAlphabet(25, new Character(charArray25));
    
    bool** charArray26 = initaliseArray();
    addToAlphabet(26, new Character(charArray26));
    
    bool** charArray27 = initaliseArray();
    addToAlphabet(27, new Character(charArray27));
    
    bool** charArray28 = initaliseArray();
    addToAlphabet(28, new Character(charArray28));
    
    bool** charArray29 = initaliseArray();
    addToAlphabet(29, new Character(charArray29));
    
    bool** charArray30 = initaliseArray();
    addToAlphabet(30, new Character(charArray30));
    
    bool** charArray31 = initaliseArray();
    addToAlphabet(31, new Character(charArray31));
    
    bool** charArray32 = initaliseArray();
    addToAlphabet(32, new Character(charArray32));
    
    bool** charArray33 = initaliseArray();
    charArray33[2][0] = true;
    charArray33[2][1] = true;
    charArray33[2][2] = true;
    charArray33[2][3] = true;
    charArray33[2][4] = true;
    charArray33[2][6] = true;
    addToAlphabet(33, new Character(charArray33));
    
    bool** charArray34 = initaliseArray();
    addToAlphabet(34, new Character(charArray34));
    
    bool** charArray35 = initaliseArray();
    addToAlphabet(35, new Character(charArray35));
    
    bool** charArray36 = initaliseArray();
    addToAlphabet(36, new Character(charArray36));
    
    bool** charArray37 = initaliseArray();
    addToAlphabet(37, new Character(charArray37));
    
    bool** charArray38 = initaliseArray();
    addToAlphabet(38, new Character(charArray38));
    
    bool** charArray39 = initaliseArray();
    addToAlphabet(39, new Character(charArray39));
    
    bool** charArray40 = initaliseArray();
    addToAlphabet(40, new Character(charArray40));
    
    bool** charArray41 = initaliseArray();
    addToAlphabet(41, new Character(charArray41));
    
    bool** charArray42 = initaliseArray();
    addToAlphabet(42, new Character(charArray42));
    
    bool** charArray43 = initaliseArray();
    addToAlphabet(43, new Character(charArray43));
    
    bool** charArray44 = initaliseArray();
    addToAlphabet(44, new Character(charArray44));
    
    bool** charArray45 = initaliseArray();
    addToAlphabet(45, new Character(charArray45));
    
    bool** charArray46 = initaliseArray();
    addToAlphabet(46, new Character(charArray46));
    
    bool** charArray47 = initaliseArray();
    addToAlphabet(47, new Character(charArray47));
    
    bool** charArray48 = initaliseArray();
    charArray48[0][1] = true;
    charArray48[0][2] = true;
    charArray48[0][3] = true;
    charArray48[0][4] = true;
    charArray48[0][5] = true;
    charArray48[1][0] = true;
    charArray48[1][5] = true;
    charArray48[1][6] = true;
    charArray48[2][0] = true;
    charArray48[2][2] = true;
    charArray48[2][3] = true;
    charArray48[2][4] = true;
    charArray48[2][6] = true;
    charArray48[3][0] = true;
    charArray48[3][1] = true;
    charArray48[3][6] = true;
    charArray48[4][1] = true;
    charArray48[4][2] = true;
    charArray48[4][3] = true;
    charArray48[4][4] = true;
    charArray48[4][5] = true;
    addToAlphabet(48, new Character(charArray48));
    
    bool** charArray49 = initaliseArray();
    charArray49[1][1] = true;
    charArray49[1][6] = true;
    charArray49[2][0] = true;
    charArray49[2][1] = true;
    charArray49[2][2] = true;
    charArray49[2][3] = true;
    charArray49[2][4] = true;
    charArray49[2][5] = true;
    charArray49[2][6] = true;
    charArray49[3][6] = true;
    addToAlphabet(49, new Character(charArray49));
    
    bool** charArray50 = initaliseArray();
    charArray50[0][1] = true;
    charArray50[0][5] = true;
    charArray50[0][6] = true;
    charArray50[1][0] = true;
    charArray50[1][4] = true;
    charArray50[1][6] = true;
    charArray50[2][0] = true;
    charArray50[2][3] = true;
    charArray50[2][6] = true;
    charArray50[3][0] = true;
    charArray50[3][2] = true;
    charArray50[3][6] = true;
    charArray50[4][1] = true;
    charArray50[4][6] = true;
    addToAlphabet(50, new Character(charArray50));
    
    bool** charArray51 = initaliseArray();
    charArray51[0][1] = true;
    charArray51[0][5] = true;
    charArray51[1][0] = true;
    charArray51[1][6] = true;
    charArray51[2][0] = true;
    charArray51[2][3] = true;
    charArray51[2][6] = true;
    charArray51[3][0] = true;
    charArray51[3][3] = true;
    charArray51[3][6] = true;
    charArray51[4][1] = true;
    charArray51[4][2] = true;
    charArray51[4][4] = true;
    charArray51[4][5] = true;
    addToAlphabet(51, new Character(charArray51));
    
    bool** charArray52 = initaliseArray();
    charArray52[0][0] = true;
    charArray52[0][1] = true;
    charArray52[0][2] = true;
    charArray52[0][3] = true;
    charArray52[0][4] = true;
    charArray52[1][4] = true;
    charArray52[2][2] = true;
    charArray52[2][3] = true;
    charArray52[2][4] = true;
    charArray52[2][5] = true;
    charArray52[2][6] = true;
    charArray52[3][4] = true;
    charArray52[4][4] = true;
    addToAlphabet(52, new Character(charArray52));
    
    bool** charArray53 = initaliseArray();
    charArray53[0][0] = true;
    charArray53[0][1] = true;
    charArray53[0][2] = true;
    charArray53[0][3] = true;
    charArray53[0][5] = true;
    charArray53[1][0] = true;
    charArray53[1][3] = true;
    charArray53[1][6] = true;
    charArray53[2][0] = true;
    charArray53[2][3] = true;
    charArray53[2][6] = true;
    charArray53[3][0] = true;
    charArray53[3][3] = true;
    charArray53[3][6] = true;
    charArray53[4][0] = true;
    charArray53[4][4] = true;
    charArray53[4][5] = true;
    addToAlphabet(53, new Character(charArray53));
    
    bool** charArray54 = initaliseArray();
    charArray54[0][1] = true;
    charArray54[0][2] = true;
    charArray54[0][3] = true;
    charArray54[0][4] = true;
    charArray54[0][5] = true;
    charArray54[1][0] = true;
    charArray54[1][3] = true;
    charArray54[1][6] = true;
    charArray54[2][0] = true;
    charArray54[2][3] = true;
    charArray54[2][6] = true;
    charArray54[3][0] = true;
    charArray54[3][3] = true;
    charArray54[3][6] = true;
    charArray54[4][1] = true;
    charArray54[4][4] = true;
    charArray54[4][5] = true;
    addToAlphabet(54, new Character(charArray54));
    
    bool** charArray55 = initaliseArray();
    charArray55[0][0] = true;
    charArray55[1][0] = true;
    charArray55[1][5] = true;
    charArray55[1][6] = true;
    charArray55[2][0] = true;
    charArray55[2][3] = true;
    charArray55[2][4] = true;
    charArray55[3][0] = true;
    charArray55[3][2] = true;
    charArray55[4][0] = true;
    charArray55[4][1] = true;
    addToAlphabet(55, new Character(charArray55));
    
    bool** charArray56 = initaliseArray();
    charArray56[0][1] = true;
    charArray56[0][2] = true;
    charArray56[0][4] = true;
    charArray56[0][5] = true;
    charArray56[1][0] = true;
    charArray56[1][3] = true;
    charArray56[1][6] = true;
    charArray56[2][0] = true;
    charArray56[2][3] = true;
    charArray56[2][6] = true;
    charArray56[3][0] = true;
    charArray56[3][3] = true;
    charArray56[3][6] = true;
    charArray56[4][1] = true;
    charArray56[4][2] = true;
    charArray56[4][4] = true;
    charArray56[4][5] = true;
    addToAlphabet(56, new Character(charArray56));
    
    bool** charArray57 = initaliseArray();
    charArray57[0][1] = true;
    charArray57[0][2] = true;
    charArray57[0][5] = true;
    charArray57[1][0] = true;
    charArray57[1][3] = true;
    charArray57[1][6] = true;
    charArray57[2][0] = true;
    charArray57[2][3] = true;
    charArray57[2][6] = true;
    charArray57[3][0] = true;
    charArray57[3][3] = true;
    charArray57[3][6] = true;
    charArray57[4][1] = true;
    charArray57[4][2] = true;
    charArray57[4][3] = true;
    charArray57[4][4] = true;
    charArray57[4][5] = true;
    addToAlphabet(57, new Character(charArray57));
    
    bool** charArray58 = initaliseArray();
    addToAlphabet(58, new Character(charArray58));
    
    bool** charArray59 = initaliseArray();
    addToAlphabet(59, new Character(charArray59));
    
    bool** charArray60 = initaliseArray();
    addToAlphabet(60, new Character(charArray60));
    
    bool** charArray61 = initaliseArray();
    addToAlphabet(61, new Character(charArray61));
    
    bool** charArray62 = initaliseArray();
    addToAlphabet(62, new Character(charArray62));
    
    bool** charArray63 = initaliseArray();
    addToAlphabet(63, new Character(charArray63));
    
    bool** charArray64 = initaliseArray();
    addToAlphabet(64, new Character(charArray64));
    
    bool** charArray65 = initaliseArray();
    charArray65[0][2] = true;
    charArray65[0][3] = true;
    charArray65[0][4] = true;
    charArray65[0][5] = true;
    charArray65[0][6] = true;
    charArray65[1][1] = true;
    charArray65[1][3] = true;
    charArray65[2][0] = true;
    charArray65[2][3] = true;
    charArray65[3][1] = true;
    charArray65[3][3] = true;
    charArray65[4][2] = true;
    charArray65[4][3] = true;
    charArray65[4][4] = true;
    charArray65[4][5] = true;
    charArray65[4][6] = true;
    addToAlphabet(65, new Character(charArray65));
    
    bool** charArray66 = initaliseArray();
    charArray66[0][0] = true;
    charArray66[0][1] = true;
    charArray66[0][2] = true;
    charArray66[0][3] = true;
    charArray66[0][4] = true;
    charArray66[0][5] = true;
    charArray66[0][6] = true;
    charArray66[1][0] = true;
    charArray66[1][3] = true;
    charArray66[1][6] = true;
    charArray66[2][0] = true;
    charArray66[2][3] = true;
    charArray66[2][6] = true;
    charArray66[3][0] = true;
    charArray66[3][3] = true;
    charArray66[3][6] = true;
    charArray66[4][1] = true;
    charArray66[4][2] = true;
    charArray66[4][4] = true;
    charArray66[4][5] = true;
    addToAlphabet(66, new Character(charArray66));
    
    bool** charArray67 = initaliseArray();
    charArray67[0][1] = true;
    charArray67[0][2] = true;
    charArray67[0][3] = true;
    charArray67[0][4] = true;
    charArray67[0][5] = true;
    charArray67[1][0] = true;
    charArray67[1][6] = true;
    charArray67[2][0] = true;
    charArray67[2][6] = true;
    charArray67[3][0] = true;
    charArray67[3][6] = true;
    charArray67[4][1] = true;
    charArray67[4][5] = true;
    addToAlphabet(67, new Character(charArray67));
    
    bool** charArray68 = initaliseArray();
    charArray68[0][0] = true;
    charArray68[0][1] = true;
    charArray68[0][2] = true;
    charArray68[0][3] = true;
    charArray68[0][4] = true;
    charArray68[0][5] = true;
    charArray68[0][6] = true;
    charArray68[1][0] = true;
    charArray68[1][6] = true;
    charArray68[2][0] = true;
    charArray68[2][6] = true;
    charArray68[3][1] = true;
    charArray68[3][5] = true;
    charArray68[4][2] = true;
    charArray68[4][3] = true;
    charArray68[4][4] = true;
    addToAlphabet(68, new Character(charArray68));
    
    bool** charArray69 = initaliseArray();
    charArray69[0][0] = true;
    charArray69[0][1] = true;
    charArray69[0][2] = true;
    charArray69[0][3] = true;
    charArray69[0][4] = true;
    charArray69[0][5] = true;
    charArray69[0][6] = true;
    charArray69[1][0] = true;
    charArray69[1][3] = true;
    charArray69[1][6] = true;
    charArray69[2][0] = true;
    charArray69[2][3] = true;
    charArray69[2][6] = true;
    charArray69[3][0] = true;
    charArray69[3][3] = true;
    charArray69[3][6] = true;
    charArray69[4][0] = true;
    charArray69[4][6] = true;
    addToAlphabet(69, new Character(charArray69));
    
    bool** charArray70 = initaliseArray();
    charArray70[0][0] = true;
    charArray70[0][1] = true;
    charArray70[0][2] = true;
    charArray70[0][3] = true;
    charArray70[0][4] = true;
    charArray70[0][5] = true;
    charArray70[0][6] = true;
    charArray70[1][0] = true;
    charArray70[1][3] = true;
    charArray70[2][0] = true;
    charArray70[2][3] = true;
    charArray70[3][0] = true;
    charArray70[4][0] = true;
    addToAlphabet(70, new Character(charArray70));
    
    bool** charArray71 = initaliseArray();
    charArray71[0][1] = true;
    charArray71[0][2] = true;
    charArray71[0][3] = true;
    charArray71[0][4] = true;
    charArray71[0][5] = true;
    charArray71[1][0] = true;
    charArray71[1][6] = true;
    charArray71[2][0] = true;
    charArray71[2][6] = true;
    charArray71[3][0] = true;
    charArray71[3][4] = true;
    charArray71[3][6] = true;
    charArray71[4][1] = true;
    charArray71[4][4] = true;
    charArray71[4][5] = true;
    addToAlphabet(71, new Character(charArray71));
    
    bool** charArray72 = initaliseArray();
    charArray72[0][0] = true;
    charArray72[0][1] = true;
    charArray72[0][2] = true;
    charArray72[0][3] = true;
    charArray72[0][4] = true;
    charArray72[0][5] = true;
    charArray72[0][6] = true;
    charArray72[1][3] = true;
    charArray72[2][3] = true;
    charArray72[3][3] = true;
    charArray72[4][0] = true;
    charArray72[4][1] = true;
    charArray72[4][2] = true;
    charArray72[4][3] = true;
    charArray72[4][4] = true;
    charArray72[4][5] = true;
    charArray72[4][6] = true;
    addToAlphabet(72, new Character(charArray72));
    
    bool** charArray73 = initaliseArray();
    charArray73[0][0] = true;
    charArray73[0][6] = true;
    charArray73[1][0] = true;
    charArray73[1][6] = true;
    charArray73[2][0] = true;
    charArray73[2][1] = true;
    charArray73[2][2] = true;
    charArray73[2][3] = true;
    charArray73[2][4] = true;
    charArray73[2][5] = true;
    charArray73[2][6] = true;
    charArray73[3][0] = true;
    charArray73[3][6] = true;
    charArray73[4][0] = true;
    charArray73[4][6] = true;
    addToAlphabet(73, new Character(charArray73));
    
    bool** charArray74 = initaliseArray();
    charArray74[0][5] = true;
    charArray74[1][0] = true;
    charArray74[1][6] = true;
    charArray74[2][0] = true;
    charArray74[2][6] = true;
    charArray74[3][0] = true;
    charArray74[3][1] = true;
    charArray74[3][2] = true;
    charArray74[3][3] = true;
    charArray74[3][4] = true;
    charArray74[3][5] = true;
    charArray74[4][0] = true;
    addToAlphabet(74, new Character(charArray74));
    
    bool** charArray75 = initaliseArray();
    charArray75[0][0] = true;
    charArray75[0][1] = true;
    charArray75[0][2] = true;
    charArray75[0][3] = true;
    charArray75[0][4] = true;
    charArray75[0][5] = true;
    charArray75[0][6] = true;
    charArray75[1][4] = true;
    charArray75[2][4] = true;
    charArray75[3][2] = true;
    charArray75[3][3] = true;
    charArray75[3][5] = true;
    charArray75[4][0] = true;
    charArray75[4][1] = true;
    charArray75[4][6] = true;
    addToAlphabet(75, new Character(charArray75));
    
    bool** charArray76 = initaliseArray();
    charArray76[0][0] = true;
    charArray76[0][1] = true;
    charArray76[0][2] = true;
    charArray76[0][3] = true;
    charArray76[0][4] = true;
    charArray76[0][5] = true;
    charArray76[0][6] = true;
    charArray76[1][6] = true;
    charArray76[2][6] = true;
    charArray76[3][6] = true;
    charArray76[4][6] = true;
    addToAlphabet(76, new Character(charArray76));
    
    bool** charArray77 = initaliseArray();
    charArray77[0][0] = true;
    charArray77[0][1] = true;
    charArray77[0][2] = true;
    charArray77[0][3] = true;
    charArray77[0][4] = true;
    charArray77[0][5] = true;
    charArray77[0][6] = true;
    charArray77[1][1] = true;
    charArray77[2][2] = true;
    charArray77[3][1] = true;
    charArray77[4][0] = true;
    charArray77[4][1] = true;
    charArray77[4][2] = true;
    charArray77[4][3] = true;
    charArray77[4][4] = true;
    charArray77[4][5] = true;
    charArray77[4][6] = true;
    addToAlphabet(77, new Character(charArray77));
    
    bool** charArray78 = initaliseArray();
    charArray78[0][0] = true;
    charArray78[0][1] = true;
    charArray78[0][2] = true;
    charArray78[0][3] = true;
    charArray78[0][4] = true;
    charArray78[0][5] = true;
    charArray78[0][6] = true;
    charArray78[1][1] = true;
    charArray78[1][2] = true;
    charArray78[2][3] = true;
    charArray78[3][4] = true;
    charArray78[3][5] = true;
    charArray78[4][0] = true;
    charArray78[4][1] = true;
    charArray78[4][2] = true;
    charArray78[4][3] = true;
    charArray78[4][4] = true;
    charArray78[4][5] = true;
    charArray78[4][6] = true;
    addToAlphabet(78, new Character(charArray78));
    
    bool** charArray79 = initaliseArray();
    charArray79[0][1] = true;
    charArray79[0][2] = true;
    charArray79[0][3] = true;
    charArray79[0][4] = true;
    charArray79[0][5] = true;
    charArray79[1][0] = true;
    charArray79[1][6] = true;
    charArray79[2][0] = true;
    charArray79[2][6] = true;
    charArray79[3][0] = true;
    charArray79[3][6] = true;
    charArray79[4][1] = true;
    charArray79[4][2] = true;
    charArray79[4][3] = true;
    charArray79[4][4] = true;
    charArray79[4][5] = true;
    addToAlphabet(79, new Character(charArray79));
    
    bool** charArray80 = initaliseArray();
    charArray80[0][0] = true;
    charArray80[0][1] = true;
    charArray80[0][2] = true;
    charArray80[0][3] = true;
    charArray80[0][4] = true;
    charArray80[0][5] = true;
    charArray80[0][6] = true;
    charArray80[1][0] = true;
    charArray80[1][3] = true;
    charArray80[2][0] = true;
    charArray80[2][3] = true;
    charArray80[3][0] = true;
    charArray80[3][3] = true;
    charArray80[4][1] = true;
    charArray80[4][2] = true;
    addToAlphabet(80, new Character(charArray80));
    
    bool** charArray81 = initaliseArray();
    charArray81[0][1] = true;
    charArray81[0][2] = true;
    charArray81[0][3] = true;
    charArray81[0][4] = true;
    charArray81[0][5] = true;
    charArray81[1][0] = true;
    charArray81[1][6] = true;
    charArray81[2][0] = true;
    charArray81[2][4] = true;
    charArray81[2][6] = true;
    charArray81[3][0] = true;
    charArray81[3][5] = true;
    charArray81[3][6] = true;
    charArray81[4][1] = true;
    charArray81[4][2] = true;
    charArray81[4][3] = true;
    charArray81[4][4] = true;
    charArray81[4][5] = true;
    addToAlphabet(81, new Character(charArray81));
    
    bool** charArray82 = initaliseArray();
    charArray82[0][0] = true;
    charArray82[0][1] = true;
    charArray82[0][2] = true;
    charArray82[0][3] = true;
    charArray82[0][4] = true;
    charArray82[0][5] = true;
    charArray82[0][6] = true;
    charArray82[1][0] = true;
    charArray82[1][3] = true;
    charArray82[2][0] = true;
    charArray82[2][3] = true;
    charArray82[2][4] = true;
    charArray82[3][0] = true;
    charArray82[3][3] = true;
    charArray82[3][5] = true;
    charArray82[4][1] = true;
    charArray82[4][2] = true;
    charArray82[4][6] = true;
    addToAlphabet(82, new Character(charArray82));
    
    bool** charArray83 = initaliseArray();
    charArray83[0][1] = true;
    charArray83[0][2] = true;
    charArray83[0][5] = true;
    charArray83[1][0] = true;
    charArray83[1][3] = true;
    charArray83[1][6] = true;
    charArray83[2][0] = true;
    charArray83[2][3] = true;
    charArray83[2][6] = true;
    charArray83[3][0] = true;
    charArray83[3][3] = true;
    charArray83[3][6] = true;
    charArray83[4][1] = true;
    charArray83[4][4] = true;
    charArray83[4][5] = true;
    addToAlphabet(83, new Character(charArray83));
    
    bool** charArray84 = initaliseArray();
    charArray84[0][0] = true;
    charArray84[1][0] = true;
    charArray84[2][0] = true;
    charArray84[2][1] = true;
    charArray84[2][2] = true;
    charArray84[2][3] = true;
    charArray84[2][4] = true;
    charArray84[2][5] = true;
    charArray84[2][6] = true;
    charArray84[3][0] = true;
    charArray84[4][0] = true;
    addToAlphabet(84, new Character(charArray84));
    
    bool** charArray85 = initaliseArray();
    charArray85[0][0] = true;
    charArray85[0][1] = true;
    charArray85[0][2] = true;
    charArray85[0][3] = true;
    charArray85[0][4] = true;
    charArray85[0][5] = true;
    charArray85[1][6] = true;
    charArray85[2][6] = true;
    charArray85[3][6] = true;
    charArray85[4][0] = true;
    charArray85[4][1] = true;
    charArray85[4][2] = true;
    charArray85[4][3] = true;
    charArray85[4][4] = true;
    charArray85[4][5] = true;
    addToAlphabet(85, new Character(charArray85));
    
    bool** charArray86 = initaliseArray();
    charArray86[0][0] = true;
    charArray86[0][1] = true;
    charArray86[0][2] = true;
    charArray86[1][3] = true;
    charArray86[1][4] = true;
    charArray86[1][5] = true;
    charArray86[2][6] = true;
    charArray86[3][3] = true;
    charArray86[3][4] = true;
    charArray86[3][5] = true;
    charArray86[4][0] = true;
    charArray86[4][1] = true;
    charArray86[4][2] = true;
    addToAlphabet(86, new Character(charArray86));
    
    bool** charArray87 = initaliseArray();
    charArray87[0][0] = true;
    charArray87[0][1] = true;
    charArray87[0][2] = true;
    charArray87[0][3] = true;
    charArray87[0][4] = true;
    charArray87[0][5] = true;
    charArray87[1][6] = true;
    charArray87[2][3] = true;
    charArray87[2][4] = true;
    charArray87[2][5] = true;
    charArray87[3][6] = true;
    charArray87[4][0] = true;
    charArray87[4][1] = true;
    charArray87[4][2] = true;
    charArray87[4][3] = true;
    charArray87[4][4] = true;
    charArray87[4][5] = true;
    addToAlphabet(87, new Character(charArray87));
    
    bool** charArray88 = initaliseArray();
    charArray88[0][0] = true;
    charArray88[0][1] = true;
    charArray88[0][5] = true;
    charArray88[0][6] = true;
    charArray88[1][2] = true;
    charArray88[1][4] = true;
    charArray88[2][3] = true;
    charArray88[3][2] = true;
    charArray88[3][4] = true;
    charArray88[4][0] = true;
    charArray88[4][1] = true;
    charArray88[4][5] = true;
    charArray88[4][6] = true;
    addToAlphabet(88, new Character(charArray88));
    
    bool** charArray89 = initaliseArray();
    charArray89[0][0] = true;
    charArray89[0][1] = true;
    charArray89[1][2] = true;
    charArray89[2][3] = true;
    charArray89[2][4] = true;
    charArray89[2][5] = true;
    charArray89[2][6] = true;
    charArray89[3][2] = true;
    charArray89[4][0] = true;
    charArray89[4][1] = true;
    addToAlphabet(89, new Character(charArray89));
    
    bool** charArray90 = initaliseArray();
    charArray90[0][0] = true;
    charArray90[0][5] = true;
    charArray90[0][6] = true;
    charArray90[1][0] = true;
    charArray90[1][4] = true;
    charArray90[1][6] = true;
    charArray90[2][0] = true;
    charArray90[2][3] = true;
    charArray90[2][6] = true;
    charArray90[3][0] = true;
    charArray90[3][2] = true;
    charArray90[3][6] = true;
    charArray90[4][0] = true;
    charArray90[4][1] = true;
    charArray90[4][6] = true;
    addToAlphabet(90, new Character(charArray90));
    
    bool** charArray91 = initaliseArray();
    addToAlphabet(91, new Character(charArray91));
    
    bool** charArray92 = initaliseArray();
    addToAlphabet(92, new Character(charArray92));
    
    bool** charArray93 = initaliseArray();
    addToAlphabet(93, new Character(charArray93));
    
    bool** charArray94 = initaliseArray();
    addToAlphabet(94, new Character(charArray94));
    
    bool** charArray95 = initaliseArray();
    addToAlphabet(95, new Character(charArray95));
    
    bool** charArray96 = initaliseArray();
    addToAlphabet(96, new Character(charArray96));
    
    bool** charArray97 = initaliseArray();
    addToAlphabet(97, new Character(charArray97));
    
    bool** charArray98 = initaliseArray();
    addToAlphabet(98, new Character(charArray98));
    
    bool** charArray99 = initaliseArray();
    addToAlphabet(99, new Character(charArray99));
    
    bool** charArray100 = initaliseArray();
    addToAlphabet(100, new Character(charArray100));
    
    bool** charArray101 = initaliseArray();
    addToAlphabet(101, new Character(charArray101));
    
    bool** charArray102 = initaliseArray();
    addToAlphabet(102, new Character(charArray102));
    
    bool** charArray103 = initaliseArray();
    addToAlphabet(103, new Character(charArray103));
    
    bool** charArray104 = initaliseArray();
    addToAlphabet(104, new Character(charArray104));
    
    bool** charArray105 = initaliseArray();
    addToAlphabet(105, new Character(charArray105));
    
    bool** charArray106 = initaliseArray();
    addToAlphabet(106, new Character(charArray106));
    
    bool** charArray107 = initaliseArray();
    addToAlphabet(107, new Character(charArray107));
    
    bool** charArray108 = initaliseArray();
    addToAlphabet(108, new Character(charArray108));
    
    bool** charArray109 = initaliseArray();
    addToAlphabet(109, new Character(charArray109));
    
    bool** charArray110 = initaliseArray();
    addToAlphabet(110, new Character(charArray110));
    
    bool** charArray111 = initaliseArray();
    addToAlphabet(111, new Character(charArray111));
    
    bool** charArray112 = initaliseArray();
    addToAlphabet(112, new Character(charArray112));
    
    bool** charArray113 = initaliseArray();
    addToAlphabet(113, new Character(charArray113));
    
    bool** charArray114 = initaliseArray();
    addToAlphabet(114, new Character(charArray114));
    
    bool** charArray115 = initaliseArray();
    addToAlphabet(115, new Character(charArray115));
    
    bool** charArray116 = initaliseArray();
    addToAlphabet(116, new Character(charArray116));
    
    bool** charArray117 = initaliseArray();
    addToAlphabet(117, new Character(charArray117));
    
    bool** charArray118 = initaliseArray();
    addToAlphabet(118, new Character(charArray118));
    
    bool** charArray119 = initaliseArray();
    addToAlphabet(119, new Character(charArray119));
    
    bool** charArray120 = initaliseArray();
    addToAlphabet(120, new Character(charArray120));
    
    bool** charArray121 = initaliseArray();
    addToAlphabet(121, new Character(charArray121));
    
    bool** charArray122 = initaliseArray();
    addToAlphabet(122, new Character(charArray122));
    
    bool** charArray123 = initaliseArray();
    addToAlphabet(123, new Character(charArray123));
    
    bool** charArray124 = initaliseArray();
    addToAlphabet(124, new Character(charArray124));
    
    bool** charArray125 = initaliseArray();
    addToAlphabet(125, new Character(charArray125));
    
    bool** charArray126 = initaliseArray();
    addToAlphabet(126, new Character(charArray126));
    
    bool** charArray127 = initaliseArray();
    addToAlphabet(127, new Character(charArray127));
}