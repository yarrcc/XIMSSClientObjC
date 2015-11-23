// ----------- CommuniGate Pro: XIMSS Client Library ----------
//
// XIMSSSession.h
//   Obj-C Interface file 
//
// Created by Vladimir Butenko on 08-Aug-2010
// ---------- (c) Stalker Software, Inc. 2010-2011 ------------

#import <Foundation/Foundation.h>


// We can use the NSXML* interfaces on MacOS X only
#ifndef UseAppleXML
#  if !defined(TARGET_OS_IPHONE) && !defined(TARGET_IPHONE_SIMULATOR)
#    define UseAppleXML 1
#  else
#    define UseAppleXML 0
#  endif
#endif

#if(UseAppleXML)

#import <Foundation/NSXMLElement.h>
#import <Foundation/NSXMLDocument.h>

#define XIMSSXML NSXMLElement
@interface NSXMLElement (STLib)
-(NSString*)getAttribute:(NSString*)theName prefix:(NSString*)thePrefix;
-(void)setAttribute:(NSString*)theName prefix:(NSString*)thePrefix value:(NSString*)theValue;
-(NSString*)getTag;

-(NSString*)getTextBody;
-(NSXMLElement*)getXMLBodyByTag:(NSString*)theTag namespace:(NSString*)theNamespace index:(unsigned)index;
-(void)addTextBody:(NSString*)theText;
-(void)removeChildren;

-(NSMutableData*)dumpAsText;
+(NSXMLElement*)parseText:(const char*)pText length:(size_t)lText errorCode:(NSString**)errorCode errorPosition:(size_t*)pErrorPosition;
+(NSXMLElement*)parseText:(NSData*)theData errorCode:(NSString**)errorCode errorPosition:(size_t*)pErrorPosition;
+(NSXMLElement*)parseString:(NSString*)theString errorCode:(NSString**)errorCode;
@end

#else
#import "STXML.h"
#define XIMSSXML STXML
#endif


@interface XIMSSSession : NSObject {
	
}
+(NSString*)getVersion;
+(void)preSession:(NSDictionary*)params requests:(XIMSSXML**)xmlRequests nRequests:(unsigned)nRequests
         delegate:(NSObject*)delegate onData:(SEL*)dataSelectors onCompletion:(SEL)completedSelector;
+(void)create:(NSDictionary*)params delegate:(NSObject*)delegate onCompletion:(SEL)selector;
-(void)start;
-(void)sendRequest:(XIMSSXML*)xmlRequest delegate:(NSObject*)delegate
            onData:(SEL)dataSelector onCompletion:(SEL)completedSelector
   sendImmediately:(bool)doImmediately;
-(void)close:(NSObject*)delegate onCompletion:(SEL)theSelector;
-(bool)setAsyncProcessor:(NSObject*)delegate selector:(SEL)theSelector tagName:(NSString*)theTagName attrName:(NSString*)theAttrName attrValue:(NSString*)theAttrValue;
-(bool)setUnknownAsyncProcessor:(NSObject*)delegate selector:(SEL)theSelector;
-(bool)setNetworkErrorProcessor:(NSObject*)delegate selector:(SEL)selector timeLimit:(unsigned)timeLimit;
-(bool)setNetworkOKProcessor:(NSObject*)delegate selector:(SEL)selector;
@end



@interface XIMSSSession (Text)
-(void)sendTextRequest:(NSString*)textRequest delegate:(NSObject*)delegate
                onData:(SEL)dataSelector     onCompletion:(SEL)completedSelector
       sendImmediately:(bool)sendImmediately;
-(void)closeText:(NSObject*)delegate onCompletion:(SEL)theSelector;
-(bool)setAsyncTextProcessor:(NSObject*)delegate selector:(SEL)theSelector tagName:(NSString*)theTagName attrName:(NSString*)theAttrName attrValue:(NSString*)theAttrValue;
-(bool)setUnknownAsyncTextProcessor:(NSObject*)delegate selector:(SEL)theSelector;
@end

