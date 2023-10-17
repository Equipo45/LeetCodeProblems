class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) { return s.length(); }

        std::string stringTotal = "";
        std::map<char, int> charIndex;
        int maxCharacterLength = 0;
        int start = 0;
        //Empezamos en el indice 1 del string
        for (int i = 0; i < s.length(); i ++) {
            char caracter = s[i];
            //Buscamos si el carcater esta dentro del map ya
            //Y si no es un caracter guardado previamente
            if (charIndex.find(caracter) != charIndex.end() && charIndex[caracter] >= start) {
                //Ponemos el inicio en el siguiente indice al caracter encontrado
                start = charIndex[caracter] + 1;
            }
            
            //Guardamos el indice del caracter actual
            charIndex[caracter] = i;
            //Calcumos la distancia del caracter maximo actual
            //Sera el indice del carcater actual - el indice donde se empezo a buscar el caracter, caracteres previos a donde se empeiza no se tendran en cuenta, se le suma 1 por que se empieza contantdo desde el 0
            int currentCharLength = charIndex[caracter] - start + 1;
            //Compara el caracter mas grande con el actual
            if (maxCharacterLength < currentCharLength) {
                maxCharacterLength = currentCharLength;
            }

        }

        return maxCharacterLength;
    }
};