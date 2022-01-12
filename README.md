# 2022_MyString

This repo represent my work for MyString C++ Project :
-------------------------------------------------------


##Constructor
=============
    MyBasicString(size_t l = 0)
    MyBasicString(CharacterType *str)
 
##Destructor
============
    ~MyBasicString()

##Finder
=========
    size_t find (const MyBasicString& str, size_t pos = 0) const noexcept
    size_t find (const CharacterType* s, size_t pos = 0) const
    size_t find (const CharacterType* s, size_t pos, size_t n) const
    size_t find (CharacterType c, size_t pos = 0) const noexcept
	size_t rfind (const MyBasicString& str, size_t pos = npos) const noexcept
    size_t rfind (const CharacterType* s, size_t pos = npos) const
    size_t rfind (const CharacterType* s, size_t pos, size_t n) const
    size_t rfind (CharacterType c, size_t pos = npos) const noexcept
	size_t find_last_of (const MyBasicString& str, size_t pos = npos) const noexcept
    size_t find_last_of (const char* s, size_t pos = npos) const
    size_t find_last_of (const char* s, size_t pos, size_t n) const
    size_t find_last_of (char c, size_t pos = npos) const noexcept
    size_t find_first_of (const string& str, size_t pos = 0) const noexcept
    size_t find_first_of (const char* s, size_t pos = 0) const
    size_t find_first_of (const char* s, size_t pos, size_t n) const
    size_t find_first_of (char c, size_t pos = 0) const noexcept
    size_t find_first_not_of (const MyBasicString& str, size_t pos = 0) const noexcept
    size_t find_first_not_of (const char* s, size_t pos = 0) const
    size_t find_first_not_of (const char* s, size_t pos, size_t n) const
    size_t find_first_not_of (char c, size_t pos = 0) const noexcept
    size_t find_last_not_of (const MyBasicString& str, size_t pos = npos) const noexcept
    size_t find_last_not_of (const char* s, size_t pos = npos) const
    size_t find_last_not_of (const char* s, size_t pos, size_t n) const
    size_t find_last_not_of (char c, size_t pos = npos) const noexcept
    
##Getter
========
    CharacterType& operator[] (size_t i)
    const CharacterType& operator[] (size_t i) const
    CharacterType& at (size_t pos)
    const CharacterType& at (size_t pos) const
    CharacterType& back()
    const CharacterType& back() const
    CharacterType& front()
    const CharacterType& front() const
    const CharacterType* c_str() const noexcept
    const CharacterType* data() const noexcept
    Allocator get_allocator() const noexcept
    size_t	capacity()	const noexcept
    size_t	size()		const noexcept
    size_t	length()	const noexcept
    size_t	max_size()	const noexcept
    bool		empty()		const noexcept
    
##Clear
=======
    void		clear()		noexcept
    MyBasicString& erase (size_t pos = 0, size_t len = npos)
    
##Size function
===============
    void resize (size_t n)
    void resize (size_t n, char c)
    void shrink_to_fit()
    void reserve (size_t n = 0)
      
##Surcharge d'opérateur = (Coplien, copie, déplacement)
=======================================================
    MyBasicString& operator= (const MyBasicString& str) // copy
    MyBasicString& operator= (const CharacterType* s)
    MyBasicString& operator= (CharacterType c)
    MyBasicString& operator= (MyBasicString&& str) noexcept
    
##Apprentissage !
=================
    MyBasicString& operator+= (const MyBasicString& str)
    MyBasicString& operator+= (const CharacterType* s)
    MyBasicString& operator+= (CharacterType c)
    MyBasicString& append (const MyBasicString& str)
    MyBasicString& append (const MyBasicString& str, size_t subpos, size_t sublen)
    MyBasicString& append (const CharacterType* s)
    MyBasicString& append (const CharacterType* s, size_t n)
    MyBasicString& append (size_t n, CharacterType c)
    void push_back (char c)
    void pop_back()
    MyBasicString& insert (size_t pos, const MyBasicString& str)
    MyBasicString& insert (size_t pos, const MyBasicString& str, size_t subpos, size_t sublen)
    MyBasicString& insert (size_t pos, const CharacterType* s)
    MyBasicString& insert (size_t pos, const CharacterType* s, size_t n)
    MyBasicString& insert (size_t pos,   size_t n, CharacterType c)
    MyBasicString& replace (size_t pos, size_t len, const MyBasicString& str, size_t subpos, size_t sublen)
    MyBasicString& replace (size_t pos,        size_t len,        const CharacterType* s)
    MyBasicString& replace (size_t pos,        size_t len,        const CharacterType* s, size_t n)
    MyBasicString& replace (size_t pos,        size_t len,        const MyBasicString& str)
    
##Special Operation
===================
    void swap (MyBasicString& str)
    CharacterType *substr (size_t pos = 0, size_t len = npos) const
    size_t copy (CharacterType* s, size_t len, size_t pos = 0) const
    int compare (const MyBasicString& str) const noexcept
    int compare (size_t pos, size_t len, const MyBasicString& str) const
    int compare (const char* s) const
    int compare (size_t pos, size_t len, const char* s) const
    
    
###COPYRIGHTS###
================
©ELIE-BLACK_COMPAGNY | PANDALAB 

ADMINISTRED BY ELIANA
	
