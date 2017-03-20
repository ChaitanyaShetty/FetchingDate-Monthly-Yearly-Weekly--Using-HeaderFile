//
//  ViewController.m
//  NSDate
//
//  Created by test on 3/4/17.
//  Copyright © 2017 com.neorays. All rights reserved.
//

#import "ViewController.h"
#import "Helpher.h"

typedef enum DataType {
    Weekly,
    Monthly,
    Yearly
    
}DataType;
@interface ViewController ()
{
    DataType type;
    NSDate *currentDate;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    type = Monthly;
    currentDate = getDate([NSDate date]);
    [self setDateTitle];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)setDateTitle {
    NSString *dateString;
    if (type == Weekly) {
        dateString = getWeekDays(currentDate);
    } else if (type == Monthly) {
        dateString = getMonthName(currentDate);
    } else if (type == Yearly) {
        dateString = getYear(currentDate);
    }
    [self.dateButton setTitle:dateString forState:UIControlStateNormal];
}
- (IBAction)dateButton:(id)sender {
    UIAlertController *actionSheet = [UIAlertController alertControllerWithTitle:@"" message:@"Select "preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        [self dismissViewControllerAnimated:YES completion:nil];
    }];
    UIAlertAction *week = [UIAlertAction actionWithTitle:@"Week" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        type = Weekly;
        currentDate = getDate([NSDate date]);
        [self setDateTitle];
        [self dismissViewControllerAnimated:YES completion:nil];
        
    }];
    UIAlertAction *month = [UIAlertAction actionWithTitle:@"Month" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        type = Monthly;
        currentDate = getDate([NSDate date]);
        [self setDateTitle];
        [self dismissViewControllerAnimated:YES completion:nil];

    }];
    UIAlertAction *year = [UIAlertAction actionWithTitle:@"Year" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        type = Yearly;
        currentDate = getDate([NSDate date]);
        [self setDateTitle];
        [self dismissViewControllerAnimated:YES completion:nil];

        
    }];
    [actionSheet addAction:cancel];
    [actionSheet addAction:week];
    [actionSheet addAction:month];
    [actionSheet addAction:year];
    [self presentViewController:actionSheet animated:YES completion:nil];
}

- (IBAction)PreviousButton:(id)sender {
    if (type == Weekly) {
        currentDate = addDays(currentDate, -7);
    } else if (type == Monthly) {
        currentDate = addMonths(currentDate, -1);
    } else if (type == Yearly) {
        currentDate = addyears(currentDate, -1);
    }
    [self setDateTitle];
}

- (IBAction)NextButton:(id)sender {
    if (type == Weekly) {
        currentDate = addDays(currentDate, 7);
    } else if (type == Monthly) {
        currentDate = addMonths(currentDate, 1);
    } else if (type == Yearly) {
        currentDate = addyears(currentDate, 1);
    }
    [self setDateTitle];

}
@end
