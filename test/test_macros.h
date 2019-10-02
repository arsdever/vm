#pragma once

#define NTH( _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ... ) N

#define _CALL0( _0, ... ) \
    _0();
#define _CALL1( _0, _1, ... ) \
    _0(); _1();
#define _CALL2( _0, _1, _2 ... ) \
    _0(); _1(); _2();
#define _CALL3( _0, _1, _2, _3 ... ) \
    _0(); _1(); _2(); _3();
#define _CALL4( _0, _1, _2, _3, _4 ... ) \
    _0(); _1(); _2(); _3(); _4();
#define _CALL5( _0, _1, _2, _3, _4, _5 ... ) \
    _0(); _1(); _2(); _3(); _4(); _5();
#define _CALL6( _0, _1, _2, _3, _4, _5, _6 ... ) \
    _0(); _1(); _2(); _3(); _4(); _5(); _6();
#define _CALL7( _0, _1, _2, _3, _4, _5, _6, _7 ... ) \
    _0(); _1(); _2(); _3(); _4(); _5(); _6(); _7();
#define _CALL8( _0, _1, _2, _3, _4, _5, _6, _7, _8 ... ) \
    _0(); _1(); _2(); _3(); _4(); _5(); _6(); _7(); _8();
#define _CALL9( _0, _1, _2, _3, _4, _5, _6, _7, _8, _9 ... ) \
    _0(); _1(); _2(); _3(); _4(); _5(); _6(); _7(); _8(); _9();
#define _CALL10( _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10 ... ) \
    _0(); _1(); _2(); _3(); _4(); _5(); _6(); _7(); _8(); _9(); _10();

#define _DECL0( _0, ... ) \
private: void _0();
#define _DECL1( _0, _1, ... ) \
private: void _0(); void _1();
#define _DECL2( _0, _1, _2 ... ) \
private: void _0(); void _1(); void _2();
#define _DECL3( _0, _1, _2, _3 ... ) \
private: void _0(); void _1(); void _2(); void _3();
#define _DECL4( _0, _1, _2, _3, _4 ... ) \
private: void _0(); void _1(); void _2(); void _3(); void _4();
#define _DECL5( _0, _1, _2, _3, _4, _5 ... ) \
private: void _0(); void _1(); void _2(); void _3(); void _4(); void _5();
#define _DECL6( _0, _1, _2, _3, _4, _5, _6 ... ) \
private: void _0(); void _1(); void _2(); void _3(); void _4(); void _5(); void _6();
#define _DECL7( _0, _1, _2, _3, _4, _5, _6, _7 ... ) \
private: void _0(); void _1(); void _2(); void _3(); void _4(); void _5(); void _6(); void _7();
#define _DECL8( _0, _1, _2, _3, _4, _5, _6, _7, _8 ... ) \
private: void _0(); void _1(); void _2(); void _3(); void _4(); void _5(); void _6(); void _7(); void _8();
#define _DECL9( _0, _1, _2, _3, _4, _5, _6, _7, _8, _9 ... ) \
private: void _0(); void _1(); void _2(); void _3(); void _4(); void _5(); void _6(); void _7(); void _8(); void _9();
#define _DECL10( _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10 ... ) \
private: void _0(); void _1(); void _2(); void _3(); void _4(); void _5(); void _6(); void _7(); void _8(); void _9(); void _10();

#define DEFINE_TESTCASES( ... ) \
protected: \
    void test() override { \
        NTH( __VA_ARGS__, _CALL10, _CALL9, _CALL8, _CALL7, _CALL6, _CALL5, _CALL4, _CALL3, _CALL2, _CALL1, _CALL0 )( __VA_ARGS__ ) \
    } \
    NTH( __VA_ARGS__, _DECL10, _DECL9, _DECL8, _DECL7, _DECL6, _DECL5, _DECL4, _DECL3, _DECL2, _DECL1, _DECL0 )( __VA_ARGS__ )

#define TEST_CASE_BEGIN( __class__, __name__ ) \
void __class__ :: __name__ ()\
{ OUT_STREAM_NAME << "Testcase " << #__name__ << " started." << NEWLINE_CHAR;

#define TEST_CASE_END( __name__ ) \
OUT_STREAM_NAME << "Testcase " << #__name__ << " finished." << NEWLINE_CHAR; }

#define TESTCASE( __class__, __name__, ... ) \
TEST_CASE_BEGIN( __class__ , __name__ ) \
__VA_ARGS__ \
TEST_CASE_END( __name__ )
