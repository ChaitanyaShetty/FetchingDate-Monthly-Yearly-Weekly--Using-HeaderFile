//
//  ViewController.h
//  NSDate
//
//  Created by test on 3/4/17.
//  Copyright © 2017 com.neorays. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
@property (strong, nonatomic) IBOutlet UIButton *dateButton;
- (IBAction)dateButton:(id)sender;
- (IBAction)PreviousButton:(id)sender;
- (IBAction)NextButton:(id)sender;

@end

