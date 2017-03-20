//
//  Helpher.h
//  NSDate
//
//  Created by test on 3/4/17.
//  Copyright © 2017 com.neorays. All rights reserved.
//

#ifndef Helpher_h
#define Helpher_h
#import<Foundation/Foundation.h>
#import <UIKit/UIKit.h>

static NSDate* getDate(NSDate* date) {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitYear|NSCalendarUnitMonth|NSCalendarUnitDay) fromDate:date];
    components.hour = 0;
    components.minute = 0;
    components.second = 0;
    
    return [calendar dateFromComponents:components];
}

//static NSDate* setInitialDays(NSDate* date){
//    NSCalendar *calendar = [NSCalendar currentCalendar];
//    NSDateComponents *components = [calendar components:(NSCalendarUnitYear|NSCalendarUnitMonth|NSCalendarUnitDay) fromDate:date];
//    components.day = 1;
//    NSDate *newDate = [calendar dateFromComponents:components];
//    return newDate;
//}

static NSDate* addDays(NSDate* date, int numberOfDays){
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitYear|NSCalendarUnitMonth|NSCalendarUnitDay) fromDate:date];
    NSDate *newDate = [calendar dateFromComponents:components];
    components.day = numberOfDays;
    components.year = 0;
    components.month = 0;
    newDate = [calendar dateByAddingComponents:components toDate:newDate options:0];
    return newDate;
}

static NSDate* addMonths(NSDate* date, int numberOfMonths){
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitYear|NSCalendarUnitMonth|NSCalendarUnitDay) fromDate:date];
    NSDate *newDate = [calendar dateFromComponents:components];
    components.day = 0;
    components.month = numberOfMonths;
    components.year = 0;
    newDate = [calendar dateByAddingComponents:components toDate:newDate options:0];
    return newDate;
}

static NSDate *addyears(NSDate* date, int numberOfYears){
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitYear|NSCalendarUnitMonth|NSCalendarUnitDay) fromDate:date];
    NSDate *newDate = [calendar dateFromComponents:components];
    components.day = 0;
    components.month = 0;
    components.year = numberOfYears;
    newDate = [calendar dateByAddingComponents:components toDate:newDate options:0];
    return newDate;
}

//static NSString* getStringFromDate(NSDate* date){
//    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
//    [formatter setDateFormat:@"dd-MM-yyyy"];
//    return [formatter stringFromDate:date];
//}


static NSString* getMonthName(NSDate* date){
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    [formatter setDateFormat:@"MMMM"];
    return [formatter stringFromDate:date];
}

static NSString* getWeekDays(NSDate* date){
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    [formatter setDateFormat:@"dd-MMM"];
    NSString *startDate = [formatter stringFromDate:date];
    NSDate *endDate = addDays(date, 7);
    NSString *endDateString = [formatter stringFromDate:endDate];
    NSString *name = [NSString stringWithFormat:@"%@-%@", startDate, endDateString];
    return name;
}

static NSString* getYear(NSDate* date){
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    [formatter setDateFormat:@"yyyy"];
    return [formatter stringFromDate:date];
}

#endif /* Helpher_h */
