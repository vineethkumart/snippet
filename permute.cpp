void permute(string s, string prefix)
{
    std::cout << "call(" << s << ", " << prefix <<  endl;
    if (s.length() == 0) {
        std::cout << prefix << endl;
        return;
    }
    
    
    for (int i = 0; i < s.length(); i++) {
        // choose s[i] at each position and pass as the string, and other concatenated as perfix 
        string rem = s.substr(0, i) + s.substr(i+1);
        permute(rem, prefix + s[i]);
    }
    
}
