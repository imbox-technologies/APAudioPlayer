//
//  APAudioPlayer.h
//  APAudioPlayer
//
//  Created by Sergii Kryvoblotskyi on 5/20/14.
//  Copyright (c) 2014 Alterplay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol APAudioPlayerDelegate;

@protocol AVAudioPlayerProtocol <NSObject>
@property (readonly) NSTimeInterval duration;
@property (nonatomic, assign) float volume;
@property (nonatomic, assign) NSTimeInterval currentTime;
@property (nonatomic, assign) BOOL enableRate;
@property (nonatomic, assign) float rate;
@property (nonatomic, weak) id delegate;
- (nullable instancetype)initWithContentsOfURL:(NSURL *)url error:(NSError **)outError;
- (void)pause;
- (void)play;
- (void)stop;
- (BOOL)isPlaying;
@end

@interface APAudioPlayer : NSObject <AVAudioPlayerProtocol>

@property (nonatomic, weak) id <APAudioPlayerDelegate> delegate;

- (nullable instancetype)initWithContentsOfURL:(NSURL *)url error:(NSError **)outError;

/*
 Player interactions
 */
- (void)pause;
- (void)play;
- (void)stop;
- (BOOL)isPlaying;

/*
 Player values
 */

/* Represents duration */
@property (readonly) NSTimeInterval duration;

/* Represents current position 0..1 */
@property (nonatomic, assign) CGFloat position;

/* Represents current volume 0..1 */
@property (nonatomic, assign) float volume;

/* Represents current time */
@property (nonatomic, assign) NSTimeInterval currentTime;

/*  */
@property (nonatomic, assign) BOOL enableRate;

/*  */
@property (nonatomic, assign) float rate;

@end

@protocol APAudioPlayerDelegate <NSObject>
@optional

/**
 *  Notifies the delegate about playing status changed
 *
 *  @param player APAudioPlayer
 */
- (void)playerDidChangePlayingStatus:(APAudioPlayer *)player;

/**
 *  Will be called when track is over
 *
 *  @param player APAudioPlayer
 */
- (void)playerDidFinishPlaying:(APAudioPlayer *)player;

/**
 *   Will be called when interruption occured. For ex. phone call. Basically you should call - (void)pause in this case.
 *
 *  @param player APAudioPlayer
 */
- (void)playerBeginInterruption:(APAudioPlayer *)player;

/**
 *   Will be called when interruption ended. For ex. phone call ended. It's up to you to decide to call - (void)resume or not.
 *
 *  @param player APAudioPlayer
 *  @param should BOOL
 */
- (void)playerEndInterruption:(APAudioPlayer *)player shouldResume:(BOOL)should;

@end
