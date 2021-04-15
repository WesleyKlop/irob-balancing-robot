$fn = 100;

/**
 * Source file for the 3D printed support for the balancing robot.
 * All dimensions are in centimeters, manually measured!
 */

bot_width = 175;
bot_height = 8;
bot_depth = 45;

// Padding around the edge of the board.
padding = 5;

// Size of the 4 screw holes
hole_radius = 2;

// Stepper motor sizings
motor_width = 25;
motor_depth = 40;
motor_inset = 15;

// Size of the battery pack
battery_width = 75;
battery_depth = 40;
battery_height = 20;
battery_hole_radius = 3 / 2;
battery_hole_spacing = 20;

// Motor guard sizes
guard_width = 5;
guard_depth = motor_depth;
guard_height = 5;

tyrep_depth = (bot_depth - motor_depth) / 2;
tyrep_width = 4;


difference() {
    // Base plate
    color("#6c71c4") hull() {
        corner_radius = 2.5;
        translate([corner_radius, corner_radius, 0])
            cylinder(h=bot_height, r = corner_radius);
        translate([bot_width - corner_radius, corner_radius, 0])
            cylinder(h=bot_height, r = corner_radius);
        translate([corner_radius, bot_depth - corner_radius, 0])
            cylinder(h=bot_height, r = corner_radius);
        translate([bot_width - corner_radius, bot_depth - corner_radius, 0])
            cylinder(h=bot_height, r = corner_radius);
    }
      
    // 4 holes that align with the breadboard.
    translate([padding + hole_radius, padding + hole_radius, 0])
        cylinder(h = bot_height, r=hole_radius);
    translate([bot_width - padding - hole_radius, bot_depth - padding - hole_radius, 0])
        cylinder(h = bot_height, r=hole_radius);
    translate([bot_width - padding - hole_radius, padding + hole_radius, 0])
        cylinder(h = bot_height, r=hole_radius);
    translate([padding + hole_radius, bot_depth - padding - hole_radius, 0])
        cylinder(h = bot_height, r=hole_radius);

    // Battery holes
    translate([bot_width/2, bot_depth / 2 - (battery_hole_spacing / 2), 0])
        cylinder(h = bot_height, r = battery_hole_radius);
    translate([bot_width/2, bot_depth / 2 + (battery_hole_spacing / 2), 0])
        cylinder(h = bot_height, r = battery_hole_radius);
        
    // Tyreps
    translate([motor_inset + (motor_width / 2) - (tyrep_width / 2), 0, 0])
        cube([tyrep_width, tyrep_depth, bot_height]);
    translate([motor_inset + (motor_width / 2) - (tyrep_width / 2), bot_depth - tyrep_depth, 0])
        cube([tyrep_width, tyrep_depth, bot_height]);
        
    translate([bot_width - motor_inset - (motor_width / 2) - (tyrep_width / 2), 0, 0])
        cube([tyrep_width, tyrep_depth, bot_height]);
    translate([bot_width - motor_inset - (motor_width / 2) - (tyrep_width / 2), bot_depth - tyrep_depth, 0])
        cube([tyrep_width, tyrep_depth, bot_height]);
}

// Motors, battery packs
%union() {
    translate([motor_inset, (bot_depth - motor_depth) / 2, bot_height])
        cube([motor_width, motor_depth, motor_depth]);
    
    translate([bot_width - motor_width - motor_inset, (bot_depth - motor_depth) / 2, bot_height])
        cube([motor_width, motor_depth, motor_depth]);
    
    translate([(bot_width - battery_width) / 2, (bot_depth - battery_depth) / 2, bot_height])
        cube([battery_width, battery_depth, battery_height]);
}

// Motor guards
translate([motor_inset - guard_width, (bot_depth - motor_depth) / 2, bot_height])
    cube([guard_width, guard_depth, guard_height]);
translate([motor_inset + motor_width, (bot_depth - motor_depth) / 2, bot_height])
    cube([guard_width, guard_depth, guard_height]);

translate([bot_width - motor_inset - guard_width - motor_width, (bot_depth - motor_depth) / 2, bot_height])
    cube([guard_width, guard_depth, guard_height]);
translate([bot_width - motor_inset, (bot_depth - motor_depth) / 2, bot_height])
    cube([guard_width, guard_depth, guard_height]);