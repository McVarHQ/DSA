

string s1, s2;
     
    getline(cin, s1);
    getline(cin, s2);
     
    cout<<"Length of LCS is "<< lcs( s1, s2, s1.length(), s2.length() ) ;
     
    return 0;