#ifndef __ORG_APACHE_HARMONY_NIOCHAR_CHARSET_UTF_8_ENCODER__
#define __ORG_APACHE_HARMONY_NIOCHAR_CHARSET_UTF_8_ENCODER__

#include "xmlvm.h"

// Preprocessor constants for interfaces:
#define XMLVM_ITABLE_SIZE_org_apache_harmony_niochar_charset_UTF_8_Encoder 0
// Implemented interfaces:
// Super Class:
#include "java_nio_charset_CharsetEncoder.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_java_lang_Class
#define XMLVM_FORWARD_DECL_java_lang_Class
XMLVM_FORWARD_DECL(java_lang_Class)
#endif
#ifndef XMLVM_FORWARD_DECL_java_lang_Object
#define XMLVM_FORWARD_DECL_java_lang_Object
XMLVM_FORWARD_DECL(java_lang_Object)
#endif
#ifndef XMLVM_FORWARD_DECL_java_nio_ByteBuffer
#define XMLVM_FORWARD_DECL_java_nio_ByteBuffer
XMLVM_FORWARD_DECL(java_nio_ByteBuffer)
#endif
#ifndef XMLVM_FORWARD_DECL_java_nio_CharBuffer
#define XMLVM_FORWARD_DECL_java_nio_CharBuffer
XMLVM_FORWARD_DECL(java_nio_CharBuffer)
#endif
#ifndef XMLVM_FORWARD_DECL_java_nio_charset_Charset
#define XMLVM_FORWARD_DECL_java_nio_charset_Charset
XMLVM_FORWARD_DECL(java_nio_charset_Charset)
#endif
#ifndef XMLVM_FORWARD_DECL_java_nio_charset_CoderResult
#define XMLVM_FORWARD_DECL_java_nio_charset_CoderResult
XMLVM_FORWARD_DECL(java_nio_charset_CoderResult)
#endif
#ifndef XMLVM_FORWARD_DECL_org_apache_harmony_niochar_charset_UTF_8
#define XMLVM_FORWARD_DECL_org_apache_harmony_niochar_charset_UTF_8
XMLVM_FORWARD_DECL(org_apache_harmony_niochar_charset_UTF_8)
#endif
// Class declarations for org.apache.harmony.niochar.charset.UTF_8$Encoder
XMLVM_DEFINE_CLASS(org_apache_harmony_niochar_charset_UTF_8_Encoder, 7, XMLVM_ITABLE_SIZE_org_apache_harmony_niochar_charset_UTF_8_Encoder)

extern JAVA_OBJECT __CLASS_org_apache_harmony_niochar_charset_UTF_8_Encoder;
extern JAVA_OBJECT __CLASS_org_apache_harmony_niochar_charset_UTF_8_Encoder_1ARRAY;
extern JAVA_OBJECT __CLASS_org_apache_harmony_niochar_charset_UTF_8_Encoder_2ARRAY;
extern JAVA_OBJECT __CLASS_org_apache_harmony_niochar_charset_UTF_8_Encoder_3ARRAY;
//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_apache_harmony_niochar_charset_UTF_8_Encoder
//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_apache_harmony_niochar_charset_UTF_8_Encoder \
    __INSTANCE_FIELDS_java_nio_charset_CharsetEncoder; \
    struct { \
        JAVA_OBJECT this_0_; \
        __ADDITIONAL_INSTANCE_FIELDS_org_apache_harmony_niochar_charset_UTF_8_Encoder \
    } org_apache_harmony_niochar_charset_UTF_8_Encoder

struct org_apache_harmony_niochar_charset_UTF_8_Encoder {
    __TIB_DEFINITION_org_apache_harmony_niochar_charset_UTF_8_Encoder* tib;
    struct {
        __INSTANCE_FIELDS_org_apache_harmony_niochar_charset_UTF_8_Encoder;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_apache_harmony_niochar_charset_UTF_8_Encoder
#define XMLVM_FORWARD_DECL_org_apache_harmony_niochar_charset_UTF_8_Encoder
typedef struct org_apache_harmony_niochar_charset_UTF_8_Encoder org_apache_harmony_niochar_charset_UTF_8_Encoder;
#endif

#define XMLVM_VTABLE_SIZE_org_apache_harmony_niochar_charset_UTF_8_Encoder 7
#define XMLVM_VTABLE_IDX_org_apache_harmony_niochar_charset_UTF_8_Encoder_encodeLoop___java_nio_CharBuffer_java_nio_ByteBuffer 6

void __INIT_org_apache_harmony_niochar_charset_UTF_8_Encoder();
void __INIT_IMPL_org_apache_harmony_niochar_charset_UTF_8_Encoder();
void __DELETE_org_apache_harmony_niochar_charset_UTF_8_Encoder(void* me, void* client_data);
void __INIT_INSTANCE_MEMBERS_org_apache_harmony_niochar_charset_UTF_8_Encoder(JAVA_OBJECT me, int derivedClassWillRegisterFinalizer);
JAVA_OBJECT __NEW_org_apache_harmony_niochar_charset_UTF_8_Encoder();
JAVA_OBJECT __NEW_INSTANCE_org_apache_harmony_niochar_charset_UTF_8_Encoder();
void org_apache_harmony_niochar_charset_UTF_8_Encoder___INIT____org_apache_harmony_niochar_charset_UTF_8_java_nio_charset_Charset(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2);
// Vtable index: 6
JAVA_OBJECT org_apache_harmony_niochar_charset_UTF_8_Encoder_encodeLoop___java_nio_CharBuffer_java_nio_ByteBuffer(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2);
void org_apache_harmony_niochar_charset_UTF_8_Encoder___INIT____org_apache_harmony_niochar_charset_UTF_8_java_nio_charset_Charset_org_apache_harmony_niochar_charset_UTF_8_Encoder(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_OBJECT n3);

#endif
