// ----------- CommuniGate Pro: XIMSS Client Library ----------
//
// STXML.h
//   micro-version of the Stalker Foundation Network 
//
// Created by Vladimir Butenko on 08-Aug-2010
// ---------- (c) Stalker Software, Inc. 2010-2011 ------------

#import <Foundation/NSString.h>
#import <Foundation/NSData.h>
#import <Foundation/NSArray.h>
@class STDictionary;
@class STPrefixDictionary;


@interface STXML : NSObject {
  STXML*              parent;
  NSString*           tagName;
  NSString*           tagPrefix;
  NSString*           docType;
  NSMutableArray*     bodies;

  STDictionary*       namespaces;
  STPrefixDictionary* attributes;
}
-(id)init;
-(STXML*)initWithTag:(NSString*)theTag prefix:(NSString*)thePrefix namespace:(NSString*)theNamespace;
-(STXML*)initWithName:(NSString*)theTag;
-(NSString*)getTag;
-(NSString*)getTagPrefix;

-(NSString*)prefixForNamespace:(NSString*)namespaceName;
-(NSString*)namespaceForPrefix:(NSString*)thePrefix;
-(void)setNamespace:(NSString*)namespaceName forPrefix:(NSString*)thePrefix;


-(BOOL)isOfTag:(NSString*)theTag namespace:(NSString*)theNamespace;

-(STPrefixDictionary**)getAttributesPtr;
-(NSString*)getAttribute:(NSString*)theName prefix:(NSString*)thePrefix;
-(void)setAttribute:(NSString*)theName prefix:(NSString*)thePrefix value:(NSString*)theValue;

-(void)setTag:(NSString*)theTag prefix:(NSString*)thePrefix;
-(void)setPrefixedTag:(NSData*)prefixedTag;
-(void)setParent:(STXML*)newParent;


-(NSString*)getTextBody;
-(unsigned)childCount;
-(STXML*)childAtIndex:(unsigned)index;
-(STXML*)getXMLBodyByTag:(NSString*)theTag namespace:(NSString*)theNamespace index:(unsigned)index;

-(STXML*)addXMLBody:(STXML*)theObject;
-(void)addChild:(STXML*)theObject;
-(void)addTextBody:(NSString*)theText;
-(void)addTextBodyData:(NSData*)theText;
-(void)removeChildren;
+(STXML*)Of:(NSObject*)x;
@end

@interface STXML (PARSER)
-(void)dumpAsText:(NSMutableData*)theBuffer;
-(NSMutableData*)dumpAsText;
-(void)convertToText:(NSMutableData*)theBuffer eolString:(const char*)eolString level:(int)level;


//+(STXML*)parseStream:(STReadableStream*)theStream errorCode:(NSString**)errorCode openedDoc:(STXML*)openedDoc openTagOnly:(bool)openTagOnly;
+(STXML*)parseText:(const char*)pText length:(size_t)lText errorCode:(NSString**)errorCode errorPosition:(size_t*)pErrorPosition;
+(STXML*)parseText:(NSData*)theData errorCode:(NSString**)errorCode errorPosition:(size_t*)pErrorPosition;
+(STXML*)parseString:(NSString*)theString errorCode:(NSString**)errorCode;
@end
