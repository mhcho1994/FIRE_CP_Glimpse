# load packages
import numpy as np
import dronesim
import os
import glob
import sys
import contextlib
import matplotlib.pyplot as plt
import pandas as pd

@contextlib.contextmanager
def suppress_stdout():
    with open(os.devnull, 'w') as devnull:
        old_stdout = sys.stdout
        sys.stdout = devnull
        try:
            yield
        finally:
            sys.stdout = old_stdout

def drone_simulation(N = 1, tf = 20, dt = 0.1, type = 1, physics_fidelity = 1, cyber_fidelity = 1, attack_scenario = 0, parameter_file = "drone_specs.json", logging = True):
    if logging:
        log_dir = os.path.join(os.getcwd(),f"logs")
        os.makedirs(log_dir, exist_ok=True)
        log_path = os.path.join(log_dir, f"simulation.log")

    if type == 1:
        sim = dronesim.MFQuadrotorCoSIM(physics_fidelity = physics_fidelity, cyber_fidelity = cyber_fidelity, attack_scenario = attack_scenario, parameter_file = parameter_file, logging_file = None)
    sim_dir = os.path.join(os.getcwd(), f"results")
    os.makedirs(sim_dir, exist_ok=True)

    for idx in range(N):
        file_path = os.path.join(sim_dir, f"cosimulation_{idx+1}.csv")
        if os.path.isfile(file_path):
            os.remove(file_path)
        df = sim.simulate(tf = tf, dt = dt)
        df.to_csv(file_path, index=False)
        sim.sim_reset()

# def rover_only_simulation():

def read_plot_logs(monte_carlo_plot = 0, attack_scenario = 0):

    log_files = glob.glob(os.path.join(os.getcwd(), f"results/*.csv"))
    print(f"number of log files: {len(log_files)}, plotting ... ")

    if monte_carlo_plot == 0:
        df = pd.read_csv(log_files[0])

        if attack_scenario == 1:
            plt.figure()
            plt.subplot(3,1,1)
            plt.plot(np.array(df['time']), np.array(df['vel_w_p_b_meas[1]']), color = '#1f77b4', label = 'true velocity')
            plt.plot(np.array(df['time']), np.array(df['vel_w_p_b_fdbk[1]']), color = "#d62728", label= 'optical flow spoofing')
            plt.grid()
            plt.ylabel(r'$u (v_{forward})$ [m/s]')
            plt.ticklabel_format(axis='y', style='sci', scilimits=(0,4))
            plt.legend()
            plt.title('spoofed velocity measurement (optical flow sensor)')
            plt.subplot(3,1,2)
            plt.plot(np.array(df['time']), np.array(df['vel_w_p_b_meas[2]']), color = '#1f77b4')
            plt.plot(np.array(df['time']), np.array(df['vel_w_p_b_fdbk[2]']), color = "#d62728")
            plt.grid()
            plt.ylabel(r'$v (v_{right})$ [m/s]')
            plt.ticklabel_format(axis='y', style='sci', scilimits=(0,4))
            plt.subplot(3,1,3)
            plt.plot(np.array(df['time']), np.array(df['vel_w_p_b_meas[3]']), color = '#1f77b4')
            plt.plot(np.array(df['time']), np.array(df['vel_w_p_b_fdbk[3]']), color = "#d62728")
            plt.grid()
            plt.ylabel(r'$w (v_{down})$ [m/s]')
            plt.ticklabel_format(axis='y', style='sci', scilimits=(0,4))
            plt.xlabel('time [sec]')

            plt.figure()
            plt.subplot(3,1,1)
            plt.plot(np.array(df['time']), np.array(df['euler_wb_meas[1]'])/np.pi*180.0, color = '#1f77b4', label = 'true attitude')
            plt.grid()
            plt.ylabel(r'roll [deg]')
            plt.ticklabel_format(axis='y', style='sci', scilimits=(0,4))
            plt.legend()
            plt.title('attitude under optical flow spoofing attack')
            plt.subplot(3,1,2)
            plt.plot(np.array(df['time']), np.array(df['euler_wb_meas[2]'])/np.pi*180.0, color = '#1f77b4')
            plt.grid()
            plt.ylabel(r'pitch [deg]')
            plt.ticklabel_format(axis='y', style='sci', scilimits=(0,4))
            plt.subplot(3,1,3)
            plt.plot(np.array(df['time']), np.array(df['euler_wb_meas[3]'])/np.pi*180.0, color = '#1f77b4')
            plt.grid()
            plt.ylabel(r'yaw [deg]')
            plt.ticklabel_format(axis='y', style='sci', scilimits=(0,4))
            plt.xlabel('time [sec]')

            plt.figure()
            plt.subplot(3,1,1)
            plt.plot(np.array(df['time']), np.array(df['rate_wb_b_meas[1]'])/np.pi*180.0, color = '#1f77b4', label = 'true attitude')
            plt.grid()
            plt.ylabel(r'roll rate [deg/s]')
            plt.ticklabel_format(axis='y', style='sci', scilimits=(0,4))
            plt.legend()
            plt.title('rate under optical flow spoofing attack')
            plt.subplot(3,1,2)
            plt.plot(np.array(df['time']), np.array(df['rate_wb_b_meas[2]'])/np.pi*180.0, color = '#1f77b4')
            plt.grid()
            plt.ylabel(r'pitch rate [deg/s]')
            plt.ticklabel_format(axis='y', style='sci', scilimits=(0,4))
            plt.subplot(3,1,3)
            plt.plot(np.array(df['time']), np.array(df['rate_wb_b_meas[3]'])/np.pi*180.0, color = '#1f77b4')
            plt.grid()
            plt.ylabel(r'yaw rate [deg/s]')
            plt.ticklabel_format(axis='y', style='sci', scilimits=(0,4))
            plt.xlabel('time [sec]')

            ax = plt.figure().add_subplot(projection='3d')
            ax.plot(np.array(df['pos_w_p_w_meas[1]']), np.array(df['pos_w_p_w_meas[2]']), np.array(df['pos_w_p_w_meas[3]']), color = '#1f77b4', label='trajectory')
            ax.grid()
            ax.set_xlabel('X [m]')
            ax.set_ylabel('Y [m]')
            ax.set_zlabel('Z [m]')
            ax.set_title('3-d trajectory of drone under optical flow spoofing attack')
            ax.view_init(elev=20., azim=-35)
            ax.legend()



            # plt.figure()
            # plt.plot(np.array(df['x_meas']), np.array(df['y_meas']), color = '#1f77b4', label='trajectory')
            # plt.plot(np.array(df['x_meas'].iloc[0]), np.array(df['y_meas'].iloc[0]), color = "#b4471f", marker='o', markersize=8, label='start')
            # plt.plot(np.array(df['x_meas'].iloc[-1]), np.array(df['y_meas'].iloc[-1]), color = "#5d1fb4", marker='^', markersize=8, label='end')
            # plt.grid()
            # plt.xlabel('x [m]')
            # plt.ylabel('y [m]')
            # plt.legend()
            # plt.axis('equal')
            # plt.title('2-d trajectories of rover under EMI disturbances (harness-induced)')

            # plt.figure()
            # plt.plot(np.array(df['time']), np.array(df['vx_meas']), color = "#1f77b4", label = 'fwd (x-direction)')
            # plt.plot(np.array(df['time']), np.array(df['vy_meas']), color = "#b4471f", label = 'side (y-direction)')
            # plt.grid()
            # plt.ylabel(r'$v$ [m/s]')
            # plt.xlabel('time [sec]')
            # plt.legend()
            # plt.title('vehicle speed')

            # plt.figure()
            # plt.plot(np.array(df['time']), np.array(df['rover_8d.Vq']), color = "#1f77b4", label = 'voltage')
            # plt.plot(np.array(df['time']), np.array(df['rover_8d.Iq']), color = "#b4471f", label = 'current')
            # plt.grid()
            # plt.ylabel(r'V & I [V, A]')
            # plt.xlabel('time [sec]')
            # plt.legend()
            # plt.title('motor input voltage/current')

    # # Monte-carlo
    # plt.figure()
    # for file in log_files:
    #     df = pd.read_csv(file)
    #     plt.plot(np.array(df['x_meas']), np.array(df['y_meas']), color = '#1f77b4')
    # plt.grid()
    # plt.xlabel('x [m]')
    # plt.ylabel('y [m]')
    # plt.xlim((-5,15))
    # plt.ylim((-5,20))
    # plt.title('2-d trajectories of rover under gyro acoustic noise attack (low speed)')

    # Single-run
    # plt.figure()
    # plt.plot(np.array(df['time']), np.array(df['rover_3d.r'])/np.pi*180, color = '#1f77b4', label = 'attack-free')
    # plt.plot(np.array(df['time']), np.array(df['r_meas'])/np.pi*180, color = '#d62728', label = 'attacked')
    # plt.grid()
    # plt.legend()
    # plt.xlabel('time [sec]')
    # plt.ylabel('yaw rate [deg/s]')
    # # plt.title('yaw rate disrupted by gyro ultrasound acoustic attack (low speed)')
    # plt.title('yaw rate disrupted by EMI disturbances from cable harness')

    # plt.figure()
    # plt.plot(np.array(df['time']), np.array(df['psi_meas'])/np.pi*180, color = '#1f77b4', label = 'attack-free')
    # plt.plot(np.array(df['time']), np.array(df['psi_filtered'])/np.pi*180, color = '#d62728', label = 'attacked')
    # plt.grid()
    # plt.legend()
    # plt.xlabel('time [sec]')
    # plt.ylabel('heading [deg]')
    # # plt.title('heading disrupted by gyro ultrasound acoustic attack (low speed)')
    # plt.title('heading disrupted by EMI disturbances from cable harness')

    # plt.figure()
    # plt.plot(np.array(df['x_meas']), np.array(df['y_meas']), color = '#1f77b4')
    # plt.grid()
    # plt.xlabel('x [m]')
    # plt.ylabel('y [m]')
    # plt.xlim((-5,15))
    # plt.ylim((-5,20))
    # # plt.title('2-d trajectories of rover under gyro acoustic noise attack (attack-free)')
    # plt.title('2-d trajectories of rover under EMI disturbances (attack-free)')

    plt.show()


if __name__ == "__main__":

    # fidelity: 1 = low-fidelity, 2 = high-fidelity
    # attack_scneario: 0 = no-attack, 1 = emi-attack, 2 = rollover-attack
    #                  3 = gyro acoustic-noise-attack, 4 = emi-vulnerability
    # note: emi-vulnerability is only supported in high fidelity model

    # with suppress_stdout():
    #     drone_simulation(N = 1, tf = 30, dt = 0.005, attack_scenario = 1)

    read_plot_logs(monte_carlo_plot = 0, attack_scenario = 1)