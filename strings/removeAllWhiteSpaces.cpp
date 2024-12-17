void removeAllWhiteSpaces(string str){
    int si = 0 , ei = 0 ;
    for(int i = 0 ; i < str.length() ; i++ ){
        if(str[i] != ' '){
            si++ ;
            ei++ ;
        }
    }

    while (ei < str.length())
    {
        if (str[ei] != ' ')
        {
            str[si] = str[ei] ;
            si++ ;
        }
        ei++ ;
    }

    return str.substr(0,si) ;
    
}