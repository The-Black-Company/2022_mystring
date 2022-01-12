#ifndef		______BASIC_STRING______
#define		______BASIC_STRING______

#include <iostream>
#include <memory>
#include <utility>

size_t strlen (const char *str);

using namespace std;

template <typename	CharacterType, typename	Allocator = allocator<CharacterType>>
class MyBasicString
{
private:
  CharacterType		*_type;		//where are the data
  size_t		_len;		// Capacity
  Allocator		_alloc;		// allocator
  static const size_t npos = -1;
  
public:
  /*******************************************************
   **							**
   **							**
   **	        CONSTRUCTOR DESTRUCTOR			**
   **							**
   **							**
   *******************************************************/

  MyBasicString(size_t l = 0)
    : _len(l)
  {
    _type = _alloc.allocate(l + 1);
    for (int i = 0; i < (int) l + 1; ++i)
      _type[i] = 0;
  }

  MyBasicString(CharacterType *str)
    : _len(strlen(str))
  {
    _type = _alloc.allocate(_len + 1);
    for (int i = 0; i < (int) _len + 1; ++i)
      _type[i] = str[i];
  }

  ~MyBasicString()
  {
    _alloc.deallocate(_type, _len + 1);
  }
  
  /*******************************************************
   **							**
   **							**
   **		FINDER FOR CHAR				**
   **							**
   **							**
   *******************************************************/

  size_t find (const MyBasicString& str, size_t pos = 0) const noexcept
  {
    return find (str, pos, str.size());
  }
  
  size_t find (const CharacterType* s, size_t pos = 0) const
  {
    return find (s, pos, strlen(s));
  }

  size_t find (const CharacterType* s, size_t pos, size_t n) const
  {
    static const size_t le = size();
    for (size_t i = pos; i < le; i += 1)
      if (compare(&(_type[i]), s, n) == 0)
	return (i);
    return npos;
  }
  
  size_t find (CharacterType c, size_t pos = 0) const noexcept
  {
    static const size_t lim = size();
    for (size_t i = pos; i < lim; i += 1)
      if (_type[i] == c)
	return (i);
    return npos;
  }
  
  size_t rfind (const MyBasicString& str, size_t pos = npos) const noexcept
  {
    return rfind(str, pos, str.size());
  }
  
  size_t rfind (const CharacterType* s, size_t pos = npos) const
  {
    return rfind(s, pos, strlen(s));    
  }
  
  size_t rfind (const CharacterType* s, size_t pos, size_t n) const
  {
    for (size_t i = size(); i > pos; i -= 1)
      if (compare(&(_type[i]), s, n) == 0)
	return (i);
    return npos;
  }
  
  size_t rfind (CharacterType c, size_t pos = npos) const noexcept
  {
    return find_last_of (c, pos);
  }
  
  size_t find_last_of (const MyBasicString& str, size_t pos = npos) const noexcept
  {
    return find_last_of (str, pos, str.size());
  }
  
  size_t find_last_of (const char* s, size_t pos = npos) const
  {
    return find_last_of (s, pos, strlen(s));
  }
  
  size_t find_last_of (const char* s, size_t pos, size_t n) const
  {
    size_t min = npos, z = 0;
    for (min = find_last_of(s[z], pos), z = 0; z < n; z++)
      {
	if (find_last_of(s[z], pos) > min)
	  min = find_last_of(s[z], pos);
      }
    
    return min;
  }
  
  size_t find_last_of (char c, size_t pos = npos) const noexcept
  {
    for (size_t i = size(); i < pos; i -= 1)
      {
	if (_type[i] == c)
	  return (i);
      }
    return npos;
  }

  size_t find_first_of (const string& str, size_t pos = 0) const noexcept
  {
    return find_first_of (str, pos, str.size());
  }
  
  size_t find_first_of (const char* s, size_t pos = 0) const
  {
    return find_first_of (s, pos, strlen(s));    
  }
  
  size_t find_first_of (const char* s, size_t pos, size_t n) const
  {
    static const size_t le = strlen(s);
    static const size_t lim = size();
    for (size_t i = pos; i < lim; i += 1)
      for (size_t o = 0; o < le; o += 1)
	if (_type[i] == s[o])
	  return (i);
    return npos;    
  }
  
  size_t find_first_of (char c, size_t pos = 0) const noexcept
  {
    static const size_t lim = size();
    for (size_t i = pos; i < lim; i += 1)
      if (_type[i] == c)
	return (i);
    return npos;    
  }

  size_t find_first_not_of (const MyBasicString& str, size_t pos = 0) const noexcept
  {
    return find_first_not_of (str, pos, str.size());
  }
  
  size_t find_first_not_of (const char* s, size_t pos = 0) const
  {
    return find_first_not_of (s, pos, strlen(s));
  }

  size_t find_first_not_of (const char* s, size_t pos, size_t n) const
  {
    static int result = 0;
    static const size_t le = strlen(s);
    static const size_t lim = size();
    for (size_t i = pos; i < lim; i += 1)
      {
	for (size_t o = 0; o < le; o += 1)
	  if (_type[i] != s[o])
	    result ++;
	if (result == 0)
	  return (i);
	result = 0;
      }
    return npos;    
  }
  
  size_t find_first_not_of (char c, size_t pos = 0) const noexcept
  {
    static const size_t lim = size();
    for (size_t i = pos; i < lim; i += 1)
      if (_type[i] != c)
	return (i);
    return npos;
  }


  size_t find_last_not_of (const MyBasicString& str, size_t pos = npos) const noexcept
  {
    return find_last_not_of (str, pos, str.size());
  }

  size_t find_last_not_of (const char* s, size_t pos = npos) const
  {
    return find_last_not_of (s, pos, strlen(s));
  }
  
  size_t find_last_not_of (const char* s, size_t pos, size_t n) const
  {
    static size_t o = 0;
    for (int i = size() - 1; i > (int) pos; i -= 1)
      {
	for (size_t u = 0; u < n; u += 1)
	  if (_type[i] == s[u])
	    o += 1;
	if (o == 0)
	  return (i);
	o = 0;	  
      }
    return npos;    
  }

  size_t find_last_not_of (char c, size_t pos = npos) const noexcept
  {
    for (size_t i = size() - 1; i < pos; i -= 1)
      if (_type[i] != c)
	return (i);
    return npos;
  }
  

  /*******************************************************
   **							**
   **							**
   **	        GETTER					**
   **							**
   **							**
   *******************************************************/

  CharacterType& operator[] (size_t i)
  {
    return _type[i];
  }

  const CharacterType& operator[] (size_t i) const
  {
    return _type[i];
  }

  CharacterType& at (size_t pos)
  {
    return _type[pos];
  }
  
  const CharacterType& at (size_t pos) const
  {
    return _type[pos];
  }

  CharacterType& back()
  {
    return _type[length];
  }
  
  const CharacterType& back() const
  {
    return _type[length];
  }  

  CharacterType& front()
  {
    return _type[0];
  }
  
  const CharacterType& front() const
  {
    return _type[0];
  }

  const CharacterType* c_str() const noexcept
  {
    return _type;
  }

  const CharacterType* data() const noexcept
  {
    return _type;
  }

  Allocator get_allocator() const noexcept
  {
    return _alloc;
  }

  size_t	capacity()	const noexcept
  {
    return	_len;
  }

  size_t	size()		const noexcept
  {
    size_t i = 0;
    for (i = 0; _type[i] != 0 && i < _len; i += 1);
    return i;
  }

  size_t	length()	const noexcept
  {
    size_t i = 0;
    for (i = 0; _type[i] != 0 && i < _len; i += 1);
    return i;
  }

  size_t	max_size()	const noexcept
  {
    return _len;
  }

  bool		empty()		const noexcept
  {
    return (_type[0] == 0) ? true : false;
  }

  /*******************************************************
   **							**
   **							**
   **	        SIZE CHECKER				**
   **							**
   **							**
   *******************************************************/
  
  void		clear()		noexcept
  {
    for (int i = 0; i < (int) _len; ++i)
      _type[i] = 0;    
  }

  void resize (size_t n)
  {
    CharacterType cpy[_len];
    size_t old_len = _len;
    memcpy (cpy, _type, _len + 1);
    _alloc.deallocate (_type, _len + 1);
    _len = n;
    _type = _alloc.allocate (_len + 1);
    memcpy (_type, cpy, _len + 1);
    if (old_len < _len)
      for (int i = (int) old_len; i <= _len + 1; ++i)
	_type[i] = 0;    
  }
  
  void resize (size_t n, char c)
  {
    CharacterType cpy[_len];
    size_t old_len = _len;
    memcpy (cpy, _type, _len + 1);
    _alloc.deallocate (_type, _len + 1);
    _len = n;
    _type = _alloc.allocate (_len + 1);
    memcpy (_type, cpy, _len + 1);
    if (old_len < _len)
      for (int i = (int) old_len; i <= _len; ++i)
	_type[i] = c;
    _type[_len + 1] = 0;
  }

  void shrink_to_fit()
  {
    CharacterType cpy[_len];
    memcpy (cpy, _type, size());
    _alloc.deallocate (_type, _len + 1);
    _len = size();
    _type = _alloc.allocate (_len + 1);
    memcpy (_type, cpy, _len);
    _type[_len + 1] = 0;
  }

  void reserve (size_t n = 0)
  {
    if (n > _len)
      resize(n, 0);
  }

  /*******************************************************
   **							**
   **							**
   **	        SETTER					**
   **							**
   **							**
   *******************************************************/

  MyBasicString& operator= (const MyBasicString& str) // copy
  {
    printf("PASSE PAR LA CPY\n");
    _type = str._type;
    _len = str._len;
    _alloc = str._alloc;
    return *(this);
  }

  MyBasicString& operator= (const CharacterType* s)
  {
    size_t si = strlen(s);
    this->resize(si, 0);
    for (int i = 0; i != (int) si; ++i)
      _type[i] = s[i];
    return *(this);
  }
 
  MyBasicString& operator= (CharacterType c)
  {
    this->resize(1, 0);
    _type[0] = c;
    return *(this);
  }
  
  MyBasicString& operator= (MyBasicString&& str) noexcept // déplacement
  {
    printf("PASSE PAR LA MOVE\n");
    _type =	str._type;
    _len =	str._len;
    _alloc =    str._alloc;
    return *(this);
  }
  
  MyBasicString& operator+= (const MyBasicString& str)
  {
    this->append(str);
    return *(this);
  }
  
  MyBasicString& operator+= (const CharacterType* s)
  {
    size_t z = 0;
    size_t start = length();
    for (z = 0; s[z] != 0; z += 1);
    size_t si = start + z;
    this->resize(si, 0);
    for (z = 0; s[z] != 0; z += 1)
      _type[start + z] = s[z];
    return *(this);
  }
    
  MyBasicString& operator+= (CharacterType c)
  {
    size_t si = length() + 1;
    this->resize(si, 0);
    _type[length()] = c;
    return *(this);
  }
  
  MyBasicString& append (const MyBasicString& str)
  {
    size_t z = 0;
    size_t ssize = str.length();
    size_t start = length();
    size_t si = start + ssize;
    this->resize(si, 0);
    for (z = 0; z != ssize; z += 1)
      _type[start + z] = str[z];
    return *(this);
  }
  
  MyBasicString& append (const MyBasicString& str, size_t subpos, size_t sublen)
  {
    if (subpos + sublen > _len)
      resize(subpos + sublen, 0);
    for (int i = 0; i < sublen; ++i)
      _type[subpos + i] = str[i];
    return *(this);
  }
  
  MyBasicString& append (const CharacterType* s)
  {
    size_t n;
    size_t st = length();
    for (n = 0; s[n] != 0; n += 1);
    if (st + n > _len)
      resize(st + n, 0);
    for (int i = 0; i < n; ++i)
      _type[st + i] = s[i];
    return *(this);
  }
  
  MyBasicString& append (const CharacterType* s, size_t n)
  {
    size_t st = length();
    if (st + n > _len)
      resize(st + n, 0);
    for (int i = 0; i < n; ++i)
      _type[st + i] = s[i];
    return *(this);
  }

  MyBasicString& append (size_t n, CharacterType c)
  {
    size_t st = length();
    if (st + n > _len)
      resize(st + n, 0);
    for (int i = 0; i < n; ++i)
      _type[st + i] = c;
    return *(this);    
  }
  
  void push_back (char c)
  {
    append(1, c);
  }

  MyBasicString& erase (size_t pos = 0, size_t len = npos)
  {
    for (size_t o = 0; o < len; o += 1)
      for (size_t u = pos; u <  _len - 1; u += 1)
	_type[u] = _type[u + 1];
    return *(this);
  }

  void pop_back()
  {
    _type[length()] = 0;
  }

  MyBasicString& insert (size_t pos, const MyBasicString& str)
  {
    static const size_t n = str.size();
    for (size_t o = n; o > 0; o -= 1)
      insert (pos, 1, str[o]);
    return *(this);
  }
  
  MyBasicString& insert (size_t pos, const MyBasicString& str, size_t subpos, size_t sublen)
  {
    for (int o = sublen - 1; o >= 0; o -= 1)
      insert (pos, 1, str[o + subpos]);
    return *(this);
  }

  MyBasicString& insert (size_t pos, const CharacterType* s)
  {
    insert (pos, s, strlen(s));
    return *(this);
  }


  MyBasicString& insert (size_t pos, const CharacterType* s, size_t n)
  {
    for (int o = n - 1; o >= 0; o -= 1)
      insert (pos, 1, s[o]);
    return *(this);
  }

  MyBasicString& insert (size_t pos,   size_t n, CharacterType c)
  {
    if (pos + n > _len)
      reserve (pos + n + 1);
    for (int o = 0; o < n; o += 1)
      {
	for (size_t u = _len; u > pos; u-= 1)
	  _type[u] = _type[u - 1];
	_type[pos] = c;
      }    
    return *(this);
  }

  MyBasicString& replace (size_t pos,        size_t len,        const MyBasicString& str,
			   size_t subpos, size_t sublen)
  {
    MyBasicString st;
    for (int i = 0; i < sublen; ++i)
      st.append(1, str[subpos + i]);
    replace (pos, len, st);
    return *(this);    
  }
    
  MyBasicString& replace (size_t pos,        size_t len,        const CharacterType* s)
  {
    MyBasicString st;
    st = s;
    replace (pos, len, st);
    return *(this);
  }
  
  MyBasicString& replace (size_t pos,        size_t len,        const CharacterType* s, size_t n)
  {
    MyBasicString st;
    for (int i = 0; i < n; ++i)
      st.append(1, s[i]);
    replace (pos, len, st);
    return *(this);    
  }
  
  MyBasicString& replace (size_t pos,        size_t len,        const MyBasicString& str)
  {
    static const size_t flen = size();
    if (pos + len > flen)
      {
	erase(pos, len - ((pos + len) - flen));
	append (str, pos, len);
      }
    else
      {
	erase(pos, len);
	insert (pos, str, 0, str.size());
      }
    return *(this);    
  }
  
  /*******************************************************
   **							**
   **							**
   **	        SPECIAL OPERATION			**
   **							**
   **							**
   *******************************************************/

  void swap (MyBasicString& str)
  {
    std::swap (_type, str._type);
    std::swap (_len, str._len);
    std::swap (_alloc, str._alloc);    
  }

  CharacterType *substr (size_t pos = 0, size_t len = npos) const
  {
    CharacterType *std = (CharacterType *) malloc (len * sizeof(CharacterType));
    for (int i = 0; i < (int) len; ++i)
      std[i] = _type[i + pos];
    std[len] = 0;
    return std;
  }

  size_t copy (CharacterType* s, size_t len, size_t pos = 0) const
  {
    int i;
    for (i = 0; i < len; ++i)
      s[i] = _type[pos + i];
    return (size_t) i;
  }

  int compare (const MyBasicString& str) const noexcept
  {
    int i = 0;
    for (i = 0; str[i] == _type[i]; ++i);
    return _type[i] - str[i];
  }
  
  int compare (size_t pos, size_t len, const MyBasicString& str) const
  {
    int i = 0;
    for (i = 0; str[i] == _type[i + pos] && i < len; ++i);
    return _type[i + pos] - str[i];
  }

  int compare (const char* s) const
  {
    int i = 0;
    for (i = 0; s[i] == _type[i]; ++i);
    return _type[i] - s[i];
  }

  int compare (size_t pos, size_t len, const char* s) const
  {
    int i = 0;
    for (i = 0; s[i] == _type[i + pos] && i < len; ++i);
    return _type[i] - s[i + pos];
  }

  
};


typedef MyBasicString<char> MyString;
typedef MyBasicString<wchar_t> MyWString_t;
typedef MyBasicString<char16_t> MyString16_t;
typedef MyBasicString<char32_t> MyString32_t;

#endif	//______BASIC_MYBASIC_STRING______
