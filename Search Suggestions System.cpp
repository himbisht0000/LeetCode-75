class Trie_node
{
    public:
    bool is_word;
    Trie_node* alpha[26];

    bool contains_char(char ch)
    {
        return ( alpha[ ch - 'a'] != NULL );
    }

    Trie_node* char_addr(char ch)
    {
        return alpha[ ch - 'a'];
    }

    Trie_node* next_link(char ch)
    {
        return alpha[ch - 'a'];
    }

    void put_char(char ch)
    {
        Trie_node* new_node = NULL;
        new_node = new Trie_node();
        new_node->is_word = false;
        alpha[ ch - 'a'] = new_node;
    }

    void end()
    {
        is_word = true;
    }

    void print_alpha()
    {
        for(int i = 0; i < 26 ;i++)
        {
            if(alpha[i] != NULL)
            {
                cout<<(char)('a' + i)<<" ";
            }
            else
            {
                cout<<alpha[i]<<" ";
            }
        }
        cout<<endl;
    }



};

class Trie {
    
public:
    Trie_node* root;
    Trie() {
        root = new Trie_node();
        root->is_word = false;
    }
    
    void insert(string word) {
       Trie_node* node = root;
       for(int i=0; i < word.length(); i++)
       {
            if(false == node->contains_char(word[i]))
            {
                node->put_char(word[i]);  
                //cout<<word[i]<<endl;
                //node->print_alpha();
            }
            node = node->next_link(word[i]);
       }

        //ode->print_alpha();
       node->end();
    }
    
    bool search(string word) {
        
        Trie_node *node = root;
        for(int i = 0 ; i < word.length(); i++)
        {   
            //node->print_alpha();
            if( node == NULL || false == node->contains_char(word[i]) )
            {
                return false;
            }
            node =  node->next_link(word[i]);
            //cout<<"ok--"<<endl;
        }
        if(node != NULL && node->is_word == true)
        {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
         Trie_node *node = root;
        for(int i = 0 ; i < prefix.length(); i++)
        {
            if( node == NULL || false == node->contains_char(prefix[i]) )
            {
                return false;
            }
            node =  node->next_link(prefix[i]);
        }

        return true;
    }

    void similar_prefix(Trie_node* node, vector<string>&ans, string word)
    {
        char ch;
        Trie_node* current = NULL;
        // if we have already found 3 words return 
        if(NULL == node || ans.size() == 3 )
        return;

        if(true == node->is_word){
            ans.push_back(word);
        }

        for(int i = 0; i < 26 ; i++)
        {
            ch = (char)('a' + i);
            current = node->char_addr(ch);
            if(NULL != current)
            similar_prefix(current,ans,word + ch);
        }

    }
    vector<string> suggestion(string prefix)
    {
        Trie_node* node = root;
        Trie_node* current = NULL;
        vector<string> answer;

        char ch;
        for(int i = 0; i < prefix.length() ; i++)
        {
            node = node->next_link(prefix[i]);
            if(node == NULL)
            return answer;
        }
        
        if(true == node->is_word)
        {
            answer.push_back(prefix);
        }

        for(int i = 0; i < 26 ; i++)
        {
            ch = (char)('a' + i);
            current = node->char_addr(ch);
            if(NULL != current)
            similar_prefix(current, answer, prefix + ch);
        }

        return answer;
        
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        
        for(int i = 0; i < products.size() ; i++)
        {
            trie->insert(products[i]);
        }

        vector<vector<string>> answer;
        string prefix;
        for(int i=0 ; i < searchWord.length() ; i++)
        {
            prefix+=searchWord[i];
            answer.push_back(trie->suggestion(prefix));
        }

        return answer;

    }
};
